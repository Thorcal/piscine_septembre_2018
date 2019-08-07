/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spuisais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 14:50:02 by spuisais          #+#    #+#             */
/*   Updated: 2018/09/18 19:47:00 by spuisais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_solve(int **arr, char *str)
{
	int row;
	int col;

	row = 0;
	col = 0;

	while (row < params.row)
	{
		arr[row] = (int*)malloc(siseof(int) * params.cols);
		col = 0;
		while (col < params.col)
		{
			if (!fill_cell(arr, row, col, *str))
					return (0);
			str++;
			col++;
		}
		row++;
		read_line(str);
	}
	return (1);
}

int		fill_cell(int **arr, int row, int col, char c)
{
	if (c == params.obstacle)
		arr[row][col] = 0;
	else if (
}
