/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anakin <anakin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 23:26:26 by anakin            #+#    #+#             */
/*   Updated: 2025/03/07 09:44:46 by anakin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void print_name(const std::string& str)
{
    if (str.length() > 10)
    {
        std::cout << str.substr(0, 9) << ".";
    }
    else
    {
        std::cout << std::string(10 - str.length(), ' ') << str;
    }
}

int PhoneBook::get_size()const
{
    return(this->size);
}

void PhoneBook::add_contact(std::string data[5])
{
    int index;
    index=this->index;
    this->contacts[index].set_firstname(data[0]);
    this->contacts[index].set_lastname(data[1]);
    this->contacts[index].set_nickname(data[2]);
    this->contacts[index].set_number(data[3]);
    this->contacts[index].set_secret(data[4]);
    this->index=(index + 1)%8;

    if(this->size < 8)
        this->size++;
}

void PhoneBook::display_contact(int i) const
{
    std::cout << "+----------+----------+----------+----------+" << std::endl;
	std::cout << "|  Contact information for specified index  |" << std::endl;
	std::cout << "+----------+----------+----------+----------+" << std::endl;

    std::cout << "First Name: " << this->contacts[i].get_firstname() << std::endl;
    std::cout << "Last Name: " << this->contacts[i].get_lastname() << std::endl;
    std::cout << "Nickname: " << this->contacts[i].get_nickname() << std::endl;
    std::cout << "Number: " << this->contacts[i].get_number() << std::endl;
    std::cout << "Darkest Secret: " << this->contacts[i].get_secret() << std::endl;
}

void PhoneBook::display_phonebook(void) const
{
    if (this->size == 0)
    {
        std::cout << "Phone book is empty!" << std::endl;
        return;
    }
    std::cout << "+----------+----------+----------+----------+" << std::endl;
    std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
    std::cout << "+----------+----------+----------+----------+" << std::endl;
    
    for (int i = 0; i < this->size; i++)
    {
            std::cout << "|" << std::setw(9) << i << "|";
            print_name(this->contacts[i].get_firstname());
            std::cout << "|";
            print_name(this->contacts[i].get_lastname());
            std::cout << "|";
            print_name(this->contacts[i].get_nickname());
            std::cout << "|" << std::endl;
    }
    std::cout << "+----------+----------+----------+----------+" << std::endl;
}