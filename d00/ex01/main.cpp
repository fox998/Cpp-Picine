
#include "Contact.hpp"
#include <iomanip>
#include <iostream>
#include <assert.h>
#include <cstdlib>
#include <string>


const size_t constactsSize = 8;
Contact contacts[constactsSize];

#define READ_CONTACT_FIELD(contact, field) { \
    std::cout << "Enter your " << (#field) << " : ";\
    std::getline(std::cin, contact.field);\
}

#define WRITE_CONTACT_FIELD(contact, field) { \
    std::cout << (#field) << " : " <<  contact.field << std::endl;\
}


Contact readContact()
{
    std::string a;
    std::getline(std::cin, a);
    Contact contact(false);
    READ_CONTACT_FIELD(contact, firstName);
    READ_CONTACT_FIELD(contact, lastName);
    READ_CONTACT_FIELD(contact, nickname);
    READ_CONTACT_FIELD(contact, login);
    READ_CONTACT_FIELD(contact, postalAddress);
    READ_CONTACT_FIELD(contact, emailAddress);
    READ_CONTACT_FIELD(contact, phoneNumber);
    READ_CONTACT_FIELD(contact, birthdayDate);
    READ_CONTACT_FIELD(contact, favoriteMeal);
    READ_CONTACT_FIELD(contact, underwearColor);
    READ_CONTACT_FIELD(contact, darkestSecret);

    return contact;
}


void add()
{
    for (size_t i = 0; i < constactsSize; i++)
    {
        if (contacts[i].isClear)
        {
            contacts[i] = readContact();
            std::cout << "Contact added" << std::endl;
            return;
        }
    }

    std::cout << "Phone Book is full...." << std::endl;
}


std::string validate_str(std::string const& str)
{
    if (str.size() < 10)
    {
        return str;
    }

    std::string const result = std::string(str.begin(), str.begin() + 9) + (str.size() > 10 ? '.' : str[9]);
    return (result.size() > 0 ? result : "None");
}


template<typename T>
inline void print_value(T val)
{
    std::cout << std::setw(10) << val << " | ";
}

void print_fields(std::string const& firstName, std::string const& lastName, std::string const& nickname)
{
    print_value(validate_str(firstName));
    print_value(validate_str(lastName) );
    print_value(validate_str(nickname) );
    std::cout << std::endl;
}


void print_phone_book()
{
    print_value("index");
    print_fields("firstName", "lastName", "nickname" );

    for (size_t i = 0; i < constactsSize; i++)
    {
        if (!contacts[i].isClear)
        {
            Contact const& contact = contacts[i];
            print_value(i);
            print_fields(
                contact.firstName,
                contact.lastName,
                contact.nickname
            );

            std::cout << std::endl;
        }
    }
}


void print_contact_by_index(std::string const& index)
{
    char* p;
    size_t const converted = strtol(index.c_str(), &p, 10);
    if (*p || converted >= constactsSize || contacts[converted].isClear) {
        // conversion failed because the input wasn't a number
        std::cout << "Wrong index" << std::endl;
    }
    else {
        // use converted
        Contact const& contact = contacts[converted];
        WRITE_CONTACT_FIELD(contact, firstName);
        WRITE_CONTACT_FIELD(contact, lastName);
        WRITE_CONTACT_FIELD(contact, nickname);
        WRITE_CONTACT_FIELD(contact, login);
        WRITE_CONTACT_FIELD(contact, postalAddress);
        WRITE_CONTACT_FIELD(contact, emailAddress);
        WRITE_CONTACT_FIELD(contact, phoneNumber);
        WRITE_CONTACT_FIELD(contact, birthdayDate);
        WRITE_CONTACT_FIELD(contact, favoriteMeal);
        WRITE_CONTACT_FIELD(contact, underwearColor);
        WRITE_CONTACT_FIELD(contact, darkestSecret);
    }

}

void search()
{
    print_phone_book();

    std::string index = "None";
    std::cout << "Enter index :";
    std::cin >> index;

    print_contact_by_index(index);
}

int main()
{
    std::cout << "Enter comand : " << std::endl;
    std::string comand;

    while (true)
    {
        std::cin >> comand;
        if (comand == "EXIT")
        {
            return 0;
        }
        else if (comand == "ADD")
        {
            add();
        }
        else if (comand == "SEARCH")
        {
           search();
        }
        else
        {
            std::cout << "Can`t recognize comand" << std::endl;
        }
    }

    return 0;
}

