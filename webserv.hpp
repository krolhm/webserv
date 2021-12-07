/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   webserv.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourgea <rbourgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 16:33:46 by rbourgea          #+#    #+#             */
/*   Updated: 2021/12/07 11:38:13 by dgoudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEBSERV_HPP
# define WEBSERV_HPP

# include <sys/socket.h>
# include <netinet/in.h>
# include <arpa/inet.h>
// DOC: https://pubs.opengroup.org/onlinepubs/007908775/xns/syssocket.h.html
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <netinet/in.h>
# include <cstring>
# include <iostream>
# include <sys/stat.h>
# include <fstream>
# include <sstream>
# include <fcntl.h>
# include <vector>
# include <poll.h>
# include <memory>
# include <map>
# include <sys/stat.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/ioctl.h>
# include <cstdlib>
#include <string>
#include <map>
#include <filesystem>

#define NC "\e[0m"
#define GRN "\e[0;32m"
#define MAG "\e[0;35m"
#define CYN "\e[0;36m"
#include "HTTPRequest.hpp"

std::vector<unsigned char>	parsing(HTTPRequest &request, std::vector<unsigned char> buffer, struct server s);
void												cgi_get();
void						parseRequest(std::vector<unsigned char> message, HTTPRequest &request);
std::vector<unsigned char>  createResponse(HTTPRequest request, struct server s);

#endif
