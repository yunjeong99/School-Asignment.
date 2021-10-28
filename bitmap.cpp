#include <stdio.h>
#pragma warning(disable:4996)

int index = 0;
char arr[300][300];
char arr2[50000];
char dap[50000];
char dap2[300][300];

void funcB(int startR, int startC, int row, int col)
{
	if (col == 0)col = 1;
	if (row == 0)row = 1;
	int same = 1;
	char temp = arr[startR][startC];
	int rowMid, colMid;

	if (row == 1 && col == 1)
	{
		dap[index++] = temp;
	}
	else
	{
		for (int i = startR; i < startR + row; i++)
		{
			for (int j = startC; j < col + startC; j++)
			{
				if (arr[i][j] != temp)
				{
					same = 0;
				}
			}
		}

		if(same==0)
		{
			dap[index++] = 'D';

			if (row == 1) rowMid = 1;
			else if (row % 2 == 0) rowMid = row / 2;
			else rowMid = row / 2 + 1;

			if (col == 1) colMid = 1;
			else if (col % 2 == 0)colMid = col / 2;
			else colMid = col / 2 + 1;

			funcB(startR, startC, rowMid, colMid);
			if (row == 1)
			{
				funcB(startR, startC + colMid, rowMid, col / 2);

			}
			else if (col == 1)
			{
				funcB(startR + rowMid, startC, row / 2, colMid);

			}
			else
			{
				funcB(startR, startC + colMid, rowMid, col / 2);
				funcB(startR + rowMid, startC, row / 2, colMid);
				funcB(startR + rowMid, startC + colMid, row / 2, col / 2);
			}

		}
		else if (same == 1)
		{
			dap[index++] = temp;
		}
	}
}

void funcD2(int startR, int startC, int row, int col)
{
	int x = startR + row;
	int y = startC + col;
	for (int i = startR; i < x; i++)
	{
		for (int j = startC; j < y; j++)
		{
			dap2[i][j] = arr2[index];
		}
	}
	index++;
}

void funcD(int startR, int startC, int row, int col)
{
	int rowMid, colMid;
	if (arr2[index] == 'D')
	{
		index++;

		if (row == 1) rowMid = 1;
		else if (row % 2 == 0) rowMid = row / 2;
		else rowMid = row / 2 + 1;

		if (col == 1) colMid = 1;
		else if (col % 2 == 0)colMid = col / 2;
		else colMid = col / 2 + 1;

		funcD(startR, startC, rowMid, colMid);
		if (row == 1)
		{
			funcD(startR, startC + colMid, rowMid, col / 2);

		}
		else if (col == 1)
		{
			funcD(startR + rowMid, startC, row / 2, colMid);

		}
		else
		{
			funcD(startR, startC + colMid, rowMid, col / 2);
			funcD(startR + rowMid, startC, row / 2, colMid);
			funcD(startR + rowMid, startC + colMid, row / 2, col / 2);
		}
	}
	else
	{
		funcD2(startR, startC, row, col);
	}

}

int main()
{
	FILE*inp = fopen("bitmap.inp", "r");
	FILE*out = fopen("bitmap.out", "w");

	for (;;)
	{
		char c, al;
		int roww, coll;
		fscanf(inp, "%c", &al);
		if (al == '#') break;
		fscanf(inp, " ");

		if (al == 'B')
		{
			int e = 0;
			fscanf(inp, "%d%d\n", &roww, &coll);
			for (int i = 0; i < roww; i++)
			{
				for (int j = 0; j < coll; j++)
				{
					fscanf(inp, "%c", &c);
					if (c == '\n')
					{
						j--; continue;
					}
					arr[i][j] = c;
				}
			}

			if (c != '\n')fscanf(inp, "\n");

			funcB(0, 0, roww, coll);

			fprintf(out, "D  %d  %d", roww, coll);
			int k;
			for (k = 0; k < index; k++)
			{
				if (k % 50 == 0) fprintf(out, "\n");
				fprintf(out, "%c", dap[k]);
			}
			index = 0;
			if (k % 50 != 0)fprintf(out, "\n");
		}

		else if (al == 'D')
		{
			fscanf(inp, "%d%d\n", &roww, &coll);
			int j = 0;
			for (int i = 0;;)
			{
				if (j == 50) j = 0;
				fscanf(inp, "%c", &c);
				if (j == 0 && c == '\n')continue;
				if (j < 50 && c == '\n') break;
				j++;
				arr2[i++] = c;
			}

			funcD(0, 0, roww, coll);

			fprintf(out, "B  %d  %d", roww, coll);

			int r = 0;
			for (int a = 0; a < roww; a++)
			{
				for (int b = 0; b < coll; b++)
				{
					if (r % 50 == 0) fprintf(out, "\n");
					fprintf(out, "%c", dap2[a][b]);
					r++;
				}
			}

			if (r % 50 != 1)fprintf(out, "\n");
			index = 0;
		}
	}

}