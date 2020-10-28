

int length_counter(char *base)
{
	int i;

	i = 0;
	while (base[i] != '\0')
		i++;
	return (i);
}

int valid(char *base)
{
	int i;
	int j;

	i = 0;
	j = 1;
	if (length_counter(base) <= 1)
		return (0);
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int ft_atoi_base(char *str, char *base)
{
	int ret;
	int i;

	i = length_counter(str);
	if (valid(base) == 0)
		return (0);
}
