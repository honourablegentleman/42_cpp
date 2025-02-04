/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoddy <jhoddy@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 13:16:08 by jhoddy            #+#    #+#             */
/*   Updated: 2024/11/08 13:16:11 by jhoddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>

void	read_replace(std::ifstream &infile, std::ofstream &outfile, char** argv)
{
	std::string	s1 = argv[2];
	std::string s2 = argv[3];
	std::string	line;
	std::string	new_line;
	size_t		pos;
	size_t		prev_pos;

	while (std::getline(infile, line))
	{
		new_line.clear();
		pos = 0;
		prev_pos = 0;
		while ((pos = line.find(s1, pos)) != std::string::npos)
		{
			new_line.append(line, prev_pos, pos - prev_pos);
			new_line.append(s2);
			pos += s1.length();
			prev_pos = pos;
		}
		new_line.append(line, prev_pos, std::string::npos);
		outfile << new_line << std::endl;
	}
}

int	main(int argc, char **argv)
{
	std::string		infile_name;
	std::string		outfile_name;
	std::ifstream	infile;
	std::ofstream	outfile;

	if (argc != 4)
	{
		std::cerr << "Incorrect number of arguments" << std::endl;
		return (1);
	}
	infile_name = argv[1];
	outfile_name = std::string(argv[1]) + ".replace";
	infile.open(infile_name.c_str(), std::ios::in);
	if (!infile)
	{
		std::cerr << "Failed to open file" << std::endl;
		return (1);
	}
	outfile.open(outfile_name.c_str(), std::ios::out);
	if (!outfile)
	{
		std::cerr << "Failed to open file" << std::endl;
		infile.close();
		return (1);
	}
	read_replace(infile, outfile, argv);
	infile.close();
	outfile.close();
	return (0);
}
