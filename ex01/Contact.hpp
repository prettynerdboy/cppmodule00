/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anakin <anakin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 22:06:33 by anakin            #+#    #+#             */
/*   Updated: 2025/03/06 06:23:53 by anakin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class Contact {
private:
    std::string firstname;
    std::string lastname;
    std::string nickname;
    std::string secret;
    std::string number;
public:
    const std::string& get_firstname(void) const;
    const std::string& get_lastname(void) const;
    const std::string& get_nickname(void) const;
    const std::string& get_secret(void) const;
    const std::string& get_number(void) const;
    void set_firstname(std::string firstname);
    void set_lastname(std::string lastname);
    void set_nickname(std::string nickname);
    void set_secret(std::string secret);
    void set_number(std::string number);
};

/*
メンバの内容を返す時、メンバの内容の変更を全て関数越しに行う。
セッター内でバリデーションを行えば、不正な値が設定されるのを防げる。
*/
