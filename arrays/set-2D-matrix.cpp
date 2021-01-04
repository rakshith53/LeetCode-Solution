class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(!matrix.size())  return false;
        
    	int height = matrix.size();
    	int width = matrix[0].size();
    
    	if(matrix[0][0] > target || matrix[height-1][width-1] < target)	return false;	
    
    	int head = 0,tail = height*width-1;
    	int mid,midRow,midCol;

    	while(head <= tail)
    	{
    		mid = (head+tail)/2;
    		midCol = mid%width;
    	    midRow = mid/width;
    		if(matrix[midRow][midCol] < target)
    			head = mid+1;
    		else if(matrix[midRow][midCol] > target)
    			tail = mid-1;
    		else
    			return true;
    	}
    	return false; 
    }
};
