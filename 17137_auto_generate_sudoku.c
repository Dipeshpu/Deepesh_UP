
/*	complete auto generate sudoku by using backtraking.
	before code send is same but this code use function and some new function add. First code not give the 		correct output this code give correct output. 
*/


#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int oksudoku(int *arr1,int n)     // put the digonal value from 1 to 9 number. all digonal value is different.
{
	if(arr1[n]==1)
		return 1;
	return 0;
}


int check_each_row(int arr[9][9],int r,int nn)  // check the row but dublicate value not hold.
{
	for(int c=0;c<9;c++)
	{
		if(arr[r][c]==nn)
			return 1;
	}
	return 0;
}

int check_each_col(int arr[9][9],int c,int nn) // check the column but dublicate value  not hold.
{

	for(int r=0;r<9;r++) 
	{
		if(arr[r][c]==nn)
			return 1;
	}
	return 0;
}

int check_3x3_box(int arr[9][9],int rr,int cc,int nn) // check the the 3x3 box but each box have store different value  and dublicate value not hold.
{
	for(int r=0;r<3;r++) 
	{
		for(int c=0;c<3;c++) 
		{
			if(arr[r+rr][c+cc]==nn)
				return 1;
		}
	}
	return 0;
}

int check_position_safe(int arr[9][9],int r,int c,int nn) //check all position value is true or not
{
	return (!check_each_row(arr,r,nn)&& !check_each_col(arr,c,nn)&& !check_3x3_box(arr,r-(r%3),c-(c%3),nn));
}

// find those value those who is 0(not put the value 1-9)
int check_no_is_zero_or_not(int arr[9][9],int *r,int *c)
{
	for(*r=0;*r<9;(*r)++)
	 {
		for(*c=0;*c<9;(*c)++) 
		{
			if(arr[*r][*c]==0)
			 {
				//printf("d\n");				
				return 1;
			}
		}
	}
	return 0;

}

//main function to solve the sudoku problem//
int main_function_of_sudoku(int arr[9][9]) 
{
	
	int r=0;
	int c=0;
	
	if(!check_no_is_zero_or_not(arr,&r,&c))
		return 1;
	
	for(int nn=1;nn<=9;nn++) 
	{
		if (check_position_safe(arr,r,c,nn)) 
		{
			arr[r][c]=nn;
			//kk++;
			if(main_function_of_sudoku(arr)) 
				return 1;
			arr[r][c] = 0;
		}
	}
	
	return 0;
}


void print_sudoku(int arr[9][9]) 
{
	int i,j;
	for(i=0;i<9;i++) 
	{
		for(j=0;j<9;j++) 
		{
			printf("%d ",arr[i][j]);
		}
		printf("\n");
	}
}




int main() 
{
int r,c,arr[9][9],nn,j;
//arr[9][9]={0};
	
for(r=0;r<9;r++)
	for(c=0;c<9;c++)
	arr[r][c]=0;	//all value in arr[9][9] is zero.


	srand(time(0));
	int arr1[10] = {0,0,0,0,0,0,0,0,0};
	for(j=0;j<=8;j++)
	{
		int nn=0;
		while(nn==0 || nn==-1 || oksudoku(arr1,nn))
		{
			nn = rand()%10;  //auto genrate the no.
			if(!oksudoku(arr1,nn) && nn!=0)  //check no is not zero
			{
				arr1[nn]=1;
				break;
			}
		}
		arr[j][j]=nn;   //put all value is differant in diagonal position.
	}

  if (main_function_of_sudoku(arr))//call the sudoku function//
	print_sudoku(arr);
  
 return 0;
}
