// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ssarkisi <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/06/24 22:12:55 by ssarkisi          #+#    #+#             //
//   Updated: 2018/06/24 22:13:00 by ssarkisi         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <ncurses.h>
#include <sys/time.h>
#include <iostream>
#include "Player.hpp"
#include "Enemy.hpp"
#include "List.hpp"
#include <unistd.h>

int					gl_x;
int					gl_y;
int					gl_x1;
int					gl_y1;
int 				gl_star;
int					cycle = 10;

List				b;
List				e;

void	drow_point(Point const &p, int color)
{
	attron(COLOR_PAIR(color));
	mvwprintw(stdscr, p.getY(), p.getX(), "%c", p.getChar());
	attroff(COLOR_PAIR(color));
}

void	draw_borders(WINDOW *screen)
{
	int		x, y;

	getmaxyx(screen, y, x);

	for (int i = 0; i < x; ++i)
	{
		mvwprintw(screen, 0, i, "-");
		mvwprintw(screen, y - 1, i, "-");
	}
}

void	change_borders(WINDOW *field, WINDOW *score, int *w, int *z, int score_size)
{
	gl_x = gl_x1;
	gl_y = gl_y1;

	wresize(field, gl_y1 - score_size, gl_x1);
	wresize(score, score_size, gl_x1);
	mvwin(score, gl_y1 - score_size, 0);

	wclear(stdscr);
	wclear(field);
	wclear(score);

	draw_borders(field);
	draw_borders(score);
	*z = (gl_y - score_size - 1) / 2;
	*w = 1;
}


void	change_user_pos(int input, int score_size, Player &user)
{
	Point p(user.getPosition());

	if(input == KEY_RIGHT)
	{
		drow_point(p, 1);
		if ((gl_x - 3) > p.getX())
			p+= Point(1, 0);
	}
	else if(input == KEY_LEFT)
	{
		drow_point(p, 1);
		if (p.getX() > 1)
			p+= Point(-1, 0);
	}
	else if(input == KEY_UP)
	{
		drow_point(p, 1);
		if (p.getY() > 1)
			p+= Point(0, -1);
	}
	else if(input == KEY_DOWN)
	{
		drow_point(p, 1);
		if ((gl_y - score_size - 2) > p.getY())
			p+= Point(0, 1);
	}
	else if(input == ' ')
	{
		b.push(new Bullet(user.getPosition(), Point(1 , 0)));
		drow_point(((Bullet *)b[b.size() - 1])->getPosition(), 6);
	}
	user.setPosition(p);
}

void	init_win()
{
	srand(time(NULL));
	initscr();
	noecho();
	cbreak();
	timeout(0);
	curs_set(0);
	start_color();
	keypad(stdscr, true);

	init_pair(1, COLOR_BLACK, COLOR_BLACK);
	init_pair(2, COLOR_YELLOW, COLOR_BLACK);
	init_pair(3, COLOR_BLUE, COLOR_BLACK);
	init_pair(4, COLOR_RED, COLOR_BLACK);
	init_pair(5, COLOR_BLUE, COLOR_YELLOW);
	init_pair(6, COLOR_WHITE, COLOR_BLACK);
}

void	init_star(Bullet *bul)
{
	for (int i = 0; i < 100; ++i)
	{
		// TODO: duplication of std::rand() % (gl_y - 5) + 1
		bul[i] = Bullet(Point(std::rand() % (gl_x - 1), std::rand() % (gl_y - 5) + 1, '.'));
	}
}

void		drow_stars(int i, Bullet *bul, Point &p, Point &pStart)
{
	// TODO: Why 20? 
	if (i % 20 != 0)
	{
		return;
	}

	for (int n = 0; n < 100; ++n)
	{
		Bullet& bullet = bul[n];
		Point const& bulletPosition = bullet.getPosition();
		
		drow_point(bulletPosition, 1);
		if (bulletPosition.getX() == 0)
		{
			pStart.setX(gl_x);
			// TODO: Why (gl_y - 5) + 1?
			pStart.setY(std::rand() % (gl_y - 5) + 1);
			bullet.setPosition(pStart);
		}
		
		bullet.move(p);
		// Don't use bulletPosition because
		// position of  was bullet chenget after bullet.setPosition(pStart)
		// TODO: Why 6?
		drow_point(bullet.getPosition(), 6);
	}
}


void drow_objects(List& objects, int color)
{
	for (int i = 0; i < objects.size(); i++)
	{
		Object* const object = static_cast<Object*>(objects[i]);
		// TODO: f?????? WTF?!
		if (object->f)
		{
			drow_point(object->getPosition(), 1);
			object->move();
			drow_point(object->getPosition(), color);
		}
	}
}

void		drow_enemy(int i)
{
	static int		a = 5;

	// WTF?
	if (i % 100 == 0 && a > 1)
	{
		a--;
	}

	if (i % 5 != 0 || std::rand() % a == 0)
	{
		return;
	}
	
	// TODO: duplication of std::rand() % (gl_y - 5) + 1
	// TODO: Why 15?
	e.push(new Enemy(Point(gl_x, std::rand() % (gl_y - 5) + 1, '#'), Point(-1, 0), 15));
	for (int i = 0; i < e.size(); i++)
	{
		Enemy* const enemy = static_cast<Enemy*>(e[i]);
		// TODO: f?????? WTF?!
		if (enemy->f)
		{
			drow_point(enemy->getPosition(), 1);
			enemy->move();
			// TODO: 4?
			drow_point(enemy->getPosition(), 4);
		}
	}
}


void		drow_bullet(int i)
{
	if (i % 5 != 0)
	{
		return;
	}

	for (int n = 0; n < b.size(); n++)
	{
		Bullet* const bullet = static_cast<Bullet *>(b[n]);
		if (bullet->f)
		{
			drow_point(bullet->getPosition(), 1);
			bullet->move();
			// TODO: Why 2?
			drow_point(bullet->getPosition(), 2); // пули
		}
	}
}
int		check_collision(Player &user)
{
	for (int i = 0; i < (int)b.size(); i++)
			for (int j = 0; j < (int)e.size(); j++)
			{
				if (((Bullet *)b[i])->f && ((Enemy *)e[j])->f)
				if (((Bullet *)b[i])->collision(*(Enemy *)e[j]))
					{
						drow_point(((Bullet *)b[i])->getPosition(), 1);
						user.upScore();
						b.erase(i);
						i--;
						e.erase(j);
						break;
					}
			}

		for (int i = 0; i < (int)e.size(); i++)
			if (((Enemy *)e[i])->f && user.collision(*(Enemy *)e[i]))
			{
				endwin();
				return (0);
			}
	return (1);
}

int main()
{
	struct timeval  tv1, tv2;

	init_win();
	int			score_size = 3;
	int			i = 0;
	getmaxyx(stdscr, gl_y, gl_x);
	int			z = (gl_y - score_size - 1) / 2;
	int			w = 1;
	int			input = getch();

	WINDOW *field = newwin(gl_y - score_size, gl_x, 0, 0);
	WINDOW *score = newwin(score_size, gl_x, gl_y - score_size, 0);
	draw_borders(field);
	draw_borders(score);

	Player		user(Point(w, z, '>'), Point(0, 0, 0), 100);
	Bullet		bul[100];
	init_star(bul);
	Point p(-1, 0);
	Point pStart(gl_x, 0);
	while(input != 27 && (++i))
	{
		gettimeofday(&tv1, NULL);
		input = getch();
		change_user_pos(input, score_size, user);
		drow_bullet(i);
		drow_stars(i, bul, p, pStart);
		drow_enemy(i);
		getmaxyx(stdscr, gl_y1, gl_x1);
		if (gl_y1 != gl_y || gl_x1 != gl_x)
			change_borders(field, score, &w, &z, score_size);
		if(check_collision(user) == 0)
			break ;
		drow_point(user.getPosition(), 5);
		wrefresh(field);
		wrefresh(score);
		if ((i + 1) % 500 == 0)
			cycle += cycle / 4;
		usleep(100000 / cycle);
		gettimeofday(&tv2, NULL);
		mvwprintw(score, 1, 1, "Time: %f", (double)(tv2.tv_usec - tv1.tv_usec) / 1000000 + (double)(tv2.tv_sec - tv1.tv_sec));
		mvwprintw(score, 1, 20, "Score: %d", user.getScore());
		mvwprintw(score, 1, 35, "Level: %d", user.getScore() / 10);
		mvwprintw(score, 1, 50, "Cycle: %d", i);
	}

	endwin();
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
	std::cout << "                 GAME OVER!                  " << std::endl;
	std::cout << "                 Level: " << user.getScore() / 10 << std::endl;
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
}
