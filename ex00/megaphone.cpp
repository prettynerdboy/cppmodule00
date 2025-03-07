/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anakin <anakin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 10:41:28 by anakin            #+#    #+#             */
/*   Updated: 2025/03/06 05:59:46 by anakin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cctype>

void toUpper(std::string &str) {
    for (std::string::size_type i = 0; i < str.length(); i++) {
        str[i] = std::toupper(static_cast<unsigned char>(str[i])); 
    }
}


int main(int argc, char **argv){
    if(argc == 1){
        std::cout <<"* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
    } else {
        for(int i = 1;i < argc ; i++){
            std::string arg(argv[i]);
            toUpper(arg);
            std::cout << arg;
        }
        std::cout<< '\n';
    }
    return (0);
}