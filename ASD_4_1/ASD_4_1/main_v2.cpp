
#include <iostream>
#include <vector>
#include <bits/stdc++.h> 

using namespace std;


vector<vector<double>> transpose_matrix(vector<vector<double>> first_matrix)
{
	vector<vector<double>> result_matrix;
	vector<vector<double>> transpose_vector(first_matrix[0].size(), vector<double>());
	for (int i = 0; i < first_matrix.size(); i++)
	{
		for (int j = 0; j < first_matrix[i].size(); j++)
		{
		    transpose_vector[j].push_back(first_matrix[i][j]);
		}
	}
	result_matrix = transpose_vector;
	return result_matrix;
}


vector<double> matrix_product(vector<vector<vector<double>>> final_product)
{
	vector<double> results;
	double result = 0;
	vector<vector<double>> first_matrix = final_product[0];
	vector<vector<double>> result_matrix = transpose_matrix(first_matrix);
	vector<vector<double>> vector = final_product[1];
	
	for(int i = 0; i < result_matrix.size(); i++)
	{
		for(int j = 0; j < result_matrix[i].size(); j++)
		{
			result += result_matrix[i][j] * vector[j][0];
		}
		results.push_back(result);
		result = 0;
	}
	return results;
}

int main() 
{
	int n, m;
	double tmp;
	
	cin >> n >> m;
	
	vector <double> first_matrix_row, second_matrix_row;
	vector < vector <double> > first_matrix, second_matrix;
	
	vector <vector <vector <double> > > final_product;

	for (int i = 0; i < m; i++)
	{
		for(int j = 0; j < n + 1; j++)
		{
			cin >> tmp;
			if (j == n)
				second_matrix_row.push_back(tmp);
			else
				first_matrix_row.push_back(tmp);
		}
		
		first_matrix.push_back(first_matrix_row);
		first_matrix_row.clear();
		
		second_matrix.push_back(second_matrix_row);
		second_matrix_row.clear();
	}
	
	final_product.push_back(first_matrix);
	final_product.push_back(second_matrix);
	
	vector <double> results = matrix_product(final_product);
	
	for(int i = 0; i< results.size(); i++)
	{
		if(i < results.size() - 1) 
			cout << fixed << setprecision(6) << results[i] << " ";
		else 
			cout << fixed << setprecision(6) << results[i];
	}
	return 0;
}
