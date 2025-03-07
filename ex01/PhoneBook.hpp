/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anakin <anakin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 22:20:05 by anakin            #+#    #+#             */
/*   Updated: 2025/03/06 06:22:47 by anakin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Contact.hpp"
#include <iostream>
#include <iomanip>

#define MAX_CONTACT 8

class PhoneBook{
private:
    Contact contacts[MAX_CONTACT];
    int size;
    int index;
public:
    PhoneBook() : size(0),index(0) {};
    int get_size(void) const;
    void add_contact(std::string data[5]);
    void display_contact(int i)const ;
    void display_phonebook(void) const ;
};