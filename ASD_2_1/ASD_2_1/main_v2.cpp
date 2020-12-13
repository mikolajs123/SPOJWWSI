
#include <iostream>
#include <vector>

using namespace std;


bool if_perpendicular(int dim, int first_matrix[], int second_matrix[]) 
{
    int tmp = 0;
    for (int i = 0; i < dim; i++) 
    {
        tmp += first_matrix[i] * second_matrix[i];
    }
    if (tmp == 0) 
        return true;
    else
        return false;
}


bool is_zero(int dims, int matrix[]) {
    int tmp = 0;
    for (int i = 0; i < dims; i++) 
    {
        if (matrix[i] == 0) 
        {
            tmp++;
        }
    }
    if (tmp == dims) 
    {
        return true;
    }
    return false;
}


void print(vector<int> matrix) 
{
    for (int element:matrix)
        cout << element << " ";
    cout << "\n";
}

int main() 
{
    int data, dims, vectors;
    vector<vector<int>> vector_1;
    cin >> data;
    if (data < 1 || data > 4) 
    {
        return 0;
    }
    for (int i = 0; i < data; i++) 
    {
        cin >> dims;
        if (dims < 2 || dims > 10) 
        {
            return 0;
        }
        cin >> vectors;
        if (vectors < 2 || vectors > 500) 
        {
            return 0;
        }
        int *origin = new int[10];
        int *vector_2 = new int[10];
        int *result = new int[10];
        for (int k = 0; k < dims; k++) 
        {
            int temp;
            cin >> temp;
            origin[k] = temp;
            result[k] = temp;
        }
        for (int m = 0; m < vectors - 1; m++) 
        {
            for (int j = 0; j < dims; j++) 
            {
                int element;
                cin >> element;
                vector_2[j] = element;
            }
            bool czyProstopadlyWektor = if_perpendicular(dims, origin, vector_2);
            if (czyProstopadlyWektor) 
            {
                for (int j = 0; j < dims; j++) 
                {
                    result[j] = result[j] + vector_2[j];
                }
                
                if (!is_zero(dims, vector_2)) 
                {
                    for (int k = 0; k < dims; k++) 
                    {
                        origin[k] = vector_2[k];
                    }
                }
            }
        }
        vector<int> tmp;
        for (int l = 0; l < dims; l++) 
        {
            tmp.push_back(result[l]);
        }
        vector_1.push_back(tmp);
    }
    for (int n = 0; n < vector_1.size(); n++) 
    {
        print(vector_1.at(n));
    }
    return 0;
}
