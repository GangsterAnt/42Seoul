/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rush01_taek.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyjung <kyjing@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 19:03:05 by kyjung            #+#    #+#             */
/*   Updated: 2020/10/24 19:03:05 by kyjung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/*
		각 row를 순회한다.
		if fixed [i][j] =='2' visited[ fixed[i][j] == '2'  건들지 않는 const값

		visited[row_num][ map [row_num][index]-1] = '2';

		에서 map [row_num][index]-1 을 하는 이유 ( 왜 -1)?

		map의 원소값은 1~n 까지의 값을 가진다
		그러나 visited[row] 의 size 는 n 으로 [0] 을 써주기 위해 한칸 당겨줘야한다..
	*/
void visited_init(int **map, char **fixed, char **visited,int size)
{

	int row_num;
	int index;


	row_num =0;
	index = 0;
	while( row_num < size)
	{
		while( index < size)
		{
			if( fixex[row_num][index] == '2')
				visited[row_num][ map [row_num][index]-1] = '2';
			else
				visited[row_num][index] ='0';
		}
	}
}


void row_init(int **map,int size,int row_num, char **visited)
{
	int m_index;
	int v_index;

	index = 0;
	v_index = 0;
	while(index < size)
	{
		if(map[row_num][index] == 0)
			while( v_index < size)
			{
				if(visited[row_num][v_index] =='0')
				{
					visited[row_num][v_index] = '1';
					map[row_num][index] = v_index + 1;  //visited는 index가 1칸씩 밀려있다.
				}
			}
	}
}

int *making_arr(int **map, char** visited,int size, int row_num)
{
	int *arr;
	int tmp;
	int p_size;
	int index;

	tmp = 0;
	p_size = size;
	index = 0;
	while( tmp < size)
		if( visited[row_num][tmp] =='2')
			p_size--;

	arr = (int *) malloc ( p_size * 4);
	tmp = 0;
	while( index < size )
	{
		if( visited[row_num][index] != '2')
			arr[tmp] = map[row_num][index];
		tmp++;
		index++;
	}

	return (arr);
}

int *sorting(int * arr, int start, int finish);
int arr_size( int **map, char **visited,int size, int row_num)
{
	int n;
	int index;

	index =0;
	n = size;
	while( index < size)
	{
		if( visietd[row_num][index] == '2')
			n--;

	}

	return (n);
}
void spray_arr(int **map, char **visited, int size, int row_num, int *arr)
{
	int index;
	int i;

	index =0;
	i =0;
	while( index < size)
	{
		if( visited[row_num][index] != '2')
			{
				map[row_num][index] =arr[i];
				i++;
			}
		index++;
	}
}
void swap(int *arr, int i, int j)
{
	int tmp;

	tmp = arr[i];
	arr[i] = arr[j];
	arr[j] = tmp;
}
int next_permutation( int **map, char **visited, int size, int row_num)
{
	int *arr;
	int n;
	int i;
	int threshold;

	n = arr_size(map,visited,size,row_num);
	arr =making_arr(map, visited, size,row_num);
	i = n -1;

	while( i > 0 && arr[i-1] >= arr[i])
		i--;
	if( i==0)
	{
		row_init(map,size,row_num, visited);
		return (-1);
	}
	threshold = i;
	sorting( arr, i,n);
	while( threshold <= n)
	{
		if( arr[i-1] < arr[threshold])
			swap( arr, i-1, threshold);
		else
			threshold++;

	}
	spray_arr(map,visited,size,row_num,arr);

}

//fixed 와 vistied 를 통해 row 생성
void rowmaker(int **map, char ** fixed,int row_num,int size)
{
	int index;
	char **visited;

	index =0;
	visited = (char **) malloc( size);
	while (index < size)	/* init visited*/
	{
		visited[index] = (char * )malloc(size);
		index++;
	}
	index = 0;
	visited_init(map,fixed,visited,size);	/*visited초기화*/
	while (index < n)
	{

	}
}

char row_check_L(int **map, int row_num, int size, int L)
{
	//row 의 좌우 값 체크
	int max_level;
	int index;
	int left_val;

	index =0;
	max_level =0;
	left_val =0
	while( index <size)
	{
		if( map[row_num][index] > max_level)
		{
			left_val++;
			max_level = map[row_num][index];
		}
		index++;
	}
	if(left_val ==L)
		return 'Y';
	return 'N';
}

char row_check_R(int **map, int row_num, int size,int R)
{
	//row 의 좌우 값 체크
	int max_level;
	int index;
	int r_val;

	index =size - 1;
	max_level =0;
	R_val =0
	while( index >= 0)
	{
		if( map[row_num][index] > max_level)
		{
			r_val++;
			max_level = map[row_num][index];
		}
		index--;
	}
	if(r_val == R)
		return 'Y';
	return
		'N';
}
