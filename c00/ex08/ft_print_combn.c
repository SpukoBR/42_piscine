#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_combination(int *arr, int n)
{
	int	i;
	int	is_last;

	i = 0;
	is_last = 1;
	while (i < n)
	{
		ft_putchar(arr[i] + '0');
		if (i != n - 1)
		{
			is_last = 0;
		}
		i++;
	}
	if (!is_last)
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	ft_combn_recursive(int *arr, int n, int depth, int start)
{
	int	i;

	if (depth == n)
	{
		print_combination(arr, n);
		return ;
	}
	i = start;
	while (i <= 9)
	{
		arr[depth] = i;
		ft_combn_recursive(arr, n, depth + 1, i + 1);
		i++;
	}
}

void	ft_print_combn(int n)
{
	int	arr[9];

	if (n > 0 && n < 10)
	{
		ft_combn_recursive(arr, n, 0, 0);
	}
}
