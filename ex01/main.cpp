/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anakin <anakin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 22:06:33 by anakin            #+#    #+#             */
/*   Updated: 2025/03/15 15:00:30 by anakin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <limits>

static bool is_valid_number(const std::string& number)
{
    if (number.empty())
        return (false);
    for (size_t i = 0; i < number.length(); i++)
    {
        if (number[i] == ' ')
            continue;
        if (number[i] < '0' || number[i] > '9')
            return (false);
    }
    return true;
}

static bool makeData(std::string data[5])
{
    std::cout << "Enter Contact Information" << std::endl;
    
    std::cout << "First Name: ";
    if (!std::getline(std::cin, data[0]))
        return (false);
    if (data[0].empty())
    {
        std::cout << "First name cannot be empty\n" << std::endl;
        return (false);
    }
    std::cout << "Last Name: ";
    if (!std::getline(std::cin, data[1]))
        return (false);
    if (data[1].empty())
    {
        std::cout << "Last name cannot be empty\n" << std::endl;
        return (false);
    }
    std::cout << "NickName: ";
    if (!std::getline(std::cin, data[2]))
        return (false);
    if (data[2].empty())
    {
        std::cout << "Nickname cannot be empty\n" << std::endl;
        return (false);
    }
    while(1)
    {    std::cout << "Phone Number: ";
        if (!std::getline(std::cin, data[3]))
            return (false);
        if (is_valid_number(data[3]))
            break;
        std::cout << "Please input a valid number" << std::endl;
    } 
    std::cout << "Darkest Secret: ";
    if (!std::getline(std::cin, data[4]))
        return (false);
    if (data[4].empty())
    {
        std::cout << "Secret cannot be empty\n" << std::endl;
        return (false);
    }
    return true;
}

static bool search(PhoneBook& phoneBook)
{
    if (phoneBook.get_size() == 0)
    {
        std::cout << "Phone book is empty!\n" << std::endl;
        return (false);
    }
    phoneBook.display_phonebook();
    std::cout << "\nInsert Index: ";
    int index;
    std::cin >> index;
    if (std::cin.fail() || index < 0 || index >= phoneBook.get_size())
    {
        std::cout << "Invalid Index!\n" << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return (false);
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    phoneBook.display_contact(index);
    return (true);
}

int main()
{
    PhoneBook phoneBook;
    std::string data[5];
    std::string input;

    while (1)
    {
        std::cout << "PhoneBook > ";
        if (!std::getline(std::cin, input))
        {
            std::cout << std::endl;
            break;
        }  
        if (input == "ADD")
        {
            if (makeData(data))
            {
                phoneBook.add_contact(data);
                std::cout << "Contact Added Successfully!\n" << std::endl;
            }
        }
        else if (input == "SEARCH")
            search(phoneBook);
        else if (input == "EXIT")
            break;
        else
            std::cout << "Invalid command\n" << std::endl;
    }
    return (0);
}

/*
std::cinは空文字を無視する。
空文字で区切った入力は区切り後のcharがバッファに残る(""で囲んでも×)
→getlineを使う
*/

/*
SEARCHエラーが起きた時のハンドリングがおかしい、前の文字が残り続けてる
入力が正しかった後の処理もおかしい
→cinは引数で与えた変数にキャストしようとするから変換ができない場合バッファに文字が残る
getlineは全てをstringとして保管するから、cinのような入力後のエラーも基本的にはない。
例外としてeofの場合 std::cin.fail() がtrueになる。
Ctrl+D を入力するとEOFになりstd::cin.fail() がtrueになる。
*/