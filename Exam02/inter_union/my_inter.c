/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_inter.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najlee <najlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 11:51:19 by najlee            #+#    #+#             */
/*   Updated: 2021/04/06 12:20:02 by najlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int argc, char *argv[]){
	
	int i = 0;
	int temp;

	if (argc == 3){
		while(argv[1][i]){
			int j = 0;
			while(argv[2][j]){
				if (argv[1][i] == argv[2][j]){
					temp = i;
					while(argv[1][--temp] && temp >= 0){
						if (argv[1][temp] == argv[1][i])
							break;
					}
					if (temp < 0)
						write(1, &argv[1][i], 1);
					break;
				}	
				j++;
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
