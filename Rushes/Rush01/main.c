void guess_horizontaly(int max,int grid[max][max],int row_up[],int row_down[],int col_left[],int col_right[])
;
void guess_vertically(int max,int grid[max][max],int row_up[],int row_down[],int col_left[],int col_right[]);


void rules_fillout(int* arr,int max,int direction,int start,int grid[max][max],int incr,int* opposite_array) {
	int min = 1;
	int i = 0;
	int fixed_2_value = 0;
	//for direction 0 -> row 1 -> column
    if(arr[incr] == max)
	{
	        i = 0;
			while(i < max)
			{
				if(direction == 0)
				{
					grid[i][incr] = min+i;
				}
			    else{
					grid[incr][i] = min+i;
				}
				i++;
			}
			i = 0;
	}

	if(arr[incr] == min)
	{
		if(direction == 1)
		{
			grid[incr][start-1] = max;
			if(opposite_array[incr] == 2){
				grid[incr][max-start] = max-1;
				// if(start > 1){
				// 	grid[incr][max/2] = max/2;
				// }else{
				// 	grid[incr][1] = max/2;
				// }
			}
			
		}
		else{
			grid[start-1][incr] = max;
			if(opposite_array[incr] == 2){
				grid[(max-start)][incr] = max-1;
				// if(start > 1){
				// 	grid[max/2][incr] = max/2;
				// }else{
				// 	grid[1][incr] = max/2;
				// }
				
			}
		}
	}

}

void print_matrix(int* row_up,int* row_down,int* col_left, int* col_right,int max,int grid[max][max])
{
	int row_index = 0;
	int col_index = 0;
	int incr = 0; // just for printing args 
	
	printf("\t");
	while(incr < 4)
		printf("%d",row_up[incr++]);
	printf("\n");
	

	printf("#########################\n");
	 while(row_index < 4) {
		col_index = 0;
		printf("%d\t",col_left[row_index]);
        while(col_index < 4) {
            printf("%d", grid[row_index][col_index]);
			col_index++;
        }
		printf("\t%d",col_right[row_index]);
		row_index++;
        printf("\n");
    }
	printf("######################### \n");

	incr = 0;
	printf("\t");
	while(incr < 4)
		printf("%d",row_down[incr++]);
	printf("\n");
}


int exist_in_array_col(int max,int arr[max][max],int value,int col)
{
	int i = 0;
	while(i < max)
	{
		if(arr[i][col] == value)
			return 1;
		i++;
	}
	return 0;
}

int exist_in_array_row(int max,int arr[max][max],int value,int row)
{
	int i = 0;
	while(i < max)
	{
		if(arr[row][i] == value)
			return 1;
		i++;
	}
	return 0;
}

void print_array(int* arr,int max)
{
	int i = 0;
	while(i < max)
	{
		printf("%d",arr[i]);
		i++;
	}
	printf("\n");
}


int    check_row(int fromleft, int fromright, int line[],int size)
{
	//printf("fromleft %d fromright %d\n",fromleft,fromright);
    // ideally this get an extra param "line_size", in this case 4
    int i;
    int last_seen_left;
    int last_seen_right;
    int counter_fromleft;
    int counter_fromright;

    counter_fromleft = 0;
    counter_fromright = 0;
    last_seen_left = 0;
    last_seen_right = 0;
    i = 0;
    while (i < 4)
    {
        if (line[i] > last_seen_left)
        {
            last_seen_left = line[i];
            counter_fromleft++;
        }
        i++;
        // i exits this loop being 1 more than the last one in the array. before turning back we need to sbstract 1
    }
    i--;
    while (i >= 0)
    {
        if (last_seen_right == 0 || line [i] > last_seen_right)
        {
            last_seen_right = line[i];
            counter_fromright++;
        }
        i--;
    }
    if (counter_fromleft == fromleft && counter_fromright == fromright)
    {
        //printf("%s", "this row is correct\n");
        return 1;
    }
    else
    {
        //printf("%s", "this row is not correct\n");
		return 0;
    }
}

void	guess_possible_numbers(int max,int tab[max][max], int col,int nb_of_fillout_cases,int* row_up,int* row_down){
	int incr = 0;
	int missing_count = max - nb_of_fillout_cases;
	int missing_values[missing_count];
	int missing_indexes[missing_count];
	int i = 0;
	int j = 0;
	int temp_array[max];
	int result = -1;
	//printf("guessing possible numbers for column %d\n",col);

	//check_row(4,1,data,max);

// fill the array with 0
	incr = 0;
	while(incr < missing_count)
	{
		missing_values[incr] = 0;
		incr++;
	}

	// fill the array with missing values
	incr = 1;
	i = 0;
	j = 0;
	while(incr <= max)
	{
		temp_array[incr-1] = tab[incr-1][col]; // fill out temp array by the way
		if(tab[incr-1][col] == 0){
			missing_indexes[j] = incr-1;
			j++;
		}
		if(!exist_in_array_col(max,tab,incr,col))
		{
				//printf("missing value %d\n",incr);
				missing_values[i] = incr;
				i++;
		}
		
		incr++;
	} 

	printf("\n");

	// print  all possible combinations of missing values with uniqueness
	incr = 0;
	i = 0;
	while(incr < missing_count)
	{
		i = 0;
		while(i < missing_count)
		{
			if(incr != i){
				if(exist_in_array_row(max,tab,missing_values[incr],missing_indexes[0]))
				{
					//printf("exist in array row\n");
					temp_array[missing_indexes[0]] = missing_values[i];
					temp_array[missing_indexes[1]] = missing_values[incr];
				}else{
					//printf("don't exist in array row\n");
					temp_array[missing_indexes[0]] = missing_values[incr];
					temp_array[missing_indexes[1]] = missing_values[i];
				}
				//printf("combination %d %d\n",missing_values[incr],missing_values[i]);
				//print_array(temp_array,max);
				result = check_row(row_up[col],row_down[col],temp_array,max);
				if (result == 1)
				{
					tab[missing_indexes[0]][col] = temp_array[missing_indexes[0]];
					tab[missing_indexes[1]][col] = temp_array[missing_indexes[1]];
				}
				return;

			}
			i++;
		}
		incr++;
	}
}


void	guess_possibles_numbers_horizontaly(int max,int tab[max][max], int row,int nb_of_fillout_cases,int* col_left,int* col_right){
	int incr = 0;
	int missing_count = max - nb_of_fillout_cases;
	int missing_values[missing_count];
	int missing_indexes[missing_count];
	int i = 0;
	int j = 0;
	int temp_array[max];
	int result = -1;



// fill the array with 0
	incr = 0;
	while(incr < missing_count)
	{
		missing_values[incr] = 0;
		incr++;
	}

	// fill the array with missing values
	incr = 1;
	i = 0;
	j = 0;
	while(incr <= max)
	{
		temp_array[incr-1] = tab[row][incr-1]; // fill out temp array by the way
		if(tab[row][incr-1] == 0){
			missing_indexes[j] = incr-1;
			j++;
		}
		if(!exist_in_array_row(max,tab,incr,row))
		{
				//printf("missing value %d\n",incr);
				missing_values[i] = incr;
				i++;
		}
		
		incr++;
	} 

	printf("\n");

	// print  all possible combinations of missing values with uniqueness
	incr = 0;
	i = 0;
	while(incr < missing_count)
	{
		i = 0;
		while(i < missing_count)
		{
			if(incr != i){
				if(exist_in_array_row(max,tab,missing_values[incr],missing_indexes[0]) && exist_in_array_col(max,tab,missing_values[incr],missing_indexes[0]))
				{
					temp_array[missing_indexes[0]] = missing_values[i];
					temp_array[missing_indexes[1]] = missing_values[incr];
				}else{
					temp_array[missing_indexes[0]] = missing_values[incr];
					temp_array[missing_indexes[1]] = missing_values[i];
				}
				//printf("combination %d %d\n",missing_values[incr],missing_values[i]);
				//print_array(temp_array,max);
				result = check_row(col_left[row],col_right[row],temp_array,max);
				if (result == 1)
				{
					tab[row][missing_indexes[0]] = temp_array[missing_indexes[0]];
					tab[row][missing_indexes[1]] = temp_array[missing_indexes[1]];
				}

			}
			i++;
		}
		incr++;
	}
}

void guess_vertically(int max,int grid[max][max],int row_up[],int row_down[],int col_left[],int col_right[])
{
	// guessing most filled out arrays vertically
	int nb_of_fillout_cases = 0;
	int row_index = 0;
	int col_index = 0;
	int index_missing = -1;
	int incr = 0; // just for printing args 
    while(col_index < max) {
		row_index = 0;
		nb_of_fillout_cases = 0;
        while(row_index < max) {
			if(grid[row_index][col_index] != 0)
			{
				//printf("row %d col %d value %d\n",row_index,col_index,grid[row_index][col_index]);
				nb_of_fillout_cases++;
			}
			else{
				index_missing = row_index;
			}
			if(nb_of_fillout_cases == 2 && row_index == max-1)
			{
             	// grab the array and start guessing
				guess_possible_numbers(max,grid,col_index,2,row_up,row_down);
				print_matrix(row_up,row_down,col_left,col_right,max,grid);
				//return 0;
			}
			
			else if (index_missing != -1 && nb_of_fillout_cases >= max-1 && col_index == max-1){
				//printf("got one missing at index %d \n",index_missing);
				while(incr <= max)
				{
					if(!exist_in_array_row(max,grid,incr,row_index) && !exist_in_array_col(max,grid,incr,col_index))
					{
						printf("missing value %d\n",incr);
							grid[index_missing][col_index] = incr;
					}
					incr++;
				} 
				print_matrix(row_up,row_down,col_left,col_right,max,grid);
			}
			else{
					//guess_vertically(max,grid,row_up,row_down,col_left,col_right);
					//guess_horizontaly(max,grid,row_up,row_down,col_left,col_right);
			}
			row_index++;
        }
		col_index++;
    }
}
void guess_horizontaly(int max,int grid[max][max],int row_up[],int row_down[],int col_left[],int col_right[])
{
		// guessing most filled out arrays horizontally
	 int nb_of_fillout_cases = 0;
	 int row_index = 0;
	 int col_index = 0;
	int incr = 1; // just for printing args 
	int missing_value = 0;
	int index_missing = -1;
    while(row_index < max) {
		col_index = 0;
		nb_of_fillout_cases = 0;
		index_missing = -1;
		incr = 1;
        while(col_index < max) {
			if(grid[row_index][col_index] != 0)
			{
				//printf("row %d col %d value %d\n",row_index,col_index,grid[row_index][col_index]);
				nb_of_fillout_cases++;
			}else{
				index_missing = col_index;
			}			
			if(nb_of_fillout_cases == 2 && col_index == max-1)
			{
				//printf("row %d col %d value %d\n",row_index,col_index,grid[row_index][col_index]);
             	// grab the array and start guessing
				guess_possibles_numbers_horizontaly(max,grid,row_index,2,col_left,col_right);
				print_matrix(row_up,row_down,col_left,col_right,max,grid);
				//return 0;
			}
			else if (index_missing != -1 && nb_of_fillout_cases >= max-1 && col_index == max-1){
				printf("got one missing at index %d \n",index_missing);
				while(incr <= max)
				{
					if(!exist_in_array_row(max,grid,incr,row_index) && !exist_in_array_col(max,grid,incr,col_index))
					{
						printf("missing value %d\n",incr);
							grid[row_index][index_missing] = incr;
					}
					incr++;
				} 
				print_matrix(row_up,row_down,col_left,col_right,max,grid);
			}else{
					//guess_vertically(max,grid,row_up,row_down,col_left,col_right);
					//guess_horizontaly(max,grid,row_up,row_down,col_left,col_right);
			}
			col_index++;
        }
		row_index++;
    }
}


int	main()
{
	int nb_left;
	int	nb_right;
	int	last_seen;
	int	start_position; // 0 -> left , 1 -> right

	int row_up[] = {2,1,2,3};
	int row_down[] = {1,3,3,2};
	int col_left[] = {2,3,3,1};
	int col_right[] = {3,2,1,2};


	int grid[4][4] = {0};
	int max = 4;
	int min = 1;



	// fill outs known values 
	int incr = 0;
	while(incr < 4)
	{
		rules_fillout(row_up,max,0,min,grid,incr,row_down);
		rules_fillout(row_down,max,0,max,grid,incr,row_up);
		rules_fillout(col_left,max,1,min,grid,incr,col_right);
		rules_fillout(col_right,max,1,max,grid,incr,col_left);
		incr++;
	}

	printf("initial grid after filling out known values\n");
    print_matrix(row_up,row_down,col_left,col_right,max,grid);

	
	guess_vertically(max,grid,row_up,row_down,col_left,col_right);
	guess_horizontaly(max,grid,row_up,row_down,col_left,col_right);
	return 0;
}
