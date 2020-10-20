class Solution {
public:
    bool isValidSudoku(vector<vector<char> >& board) {
    // Declare a valid boolean variable
      bool valid = true;
      const int brd_len = 9;
      const int n_blks = 3; // Number of blocks in x or y direction
      
      // Iterate over the rows as long as valid true
      // Check if there is any repetition
      for(int i=0;i<brd_len && valid;++i){
	vector<char> num_uniq;
	for(int j=0;j<brd_len && valid;++j){
	  // Check if non-empty char
	  if(board[i][j]!='.'){
	    if(find(num_uniq.begin(),num_uniq.end(),board[i][j])==num_uniq.end()) // If non-empty check if it already exists in your vector
	      num_uniq.push_back(board[i][j]); // If not exsists add it,
	    else
	      valid = false;  // if exists change valid to false
	  }	
	  //If empty ignore
	}
	}      

      // Iterate over the columns as long as valid true
      // Check if there is any repetition
      for(int j=0;j<brd_len && valid;++j){
	vector<char> num_uniq;
	for(int i=0;i<brd_len && valid;++i){
	  // Check if non-empty char
	  if(board[i][j]!='.'){
	    if(find(num_uniq.begin(),num_uniq.end(),board[i][j])==num_uniq.end()) // If non-empty check if it already exists in your vector
	      num_uniq.push_back(board[i][j]); // If not exsists add it,
	    else
	      valid = false;  // if exists change valid to false
	  }
	  //If empty ignore
	}
      }

      // Iterate over 3*3 boxes as long as valid is true
      // See if there is repetition
      // i represents the block, when blocks counted along rows
      // j represents the position in that block, when blocks counted along rows
      for(int p=0;p<brd_len && valid;++p){
	vector<char> num_uniq;
	for(int q=0;q<brd_len && valid;++q){
	  // Initialize locations i and j based on the blocks
	  int i = 3*div(p,n_blks).quot + div(q,n_blks).quot;
	  int j = 3*div(p,n_blks).rem + div(q,n_blks).rem; 
	  // Check if non-empty char
	  if(board[i][j]!='.'){
	    if(find(num_uniq.begin(),num_uniq.end(),board[i][j])==num_uniq.end()){ // If non-empty check if it already exists in your vector
	      num_uniq.push_back(board[i][j]); // If not exsists add it,
	    }
	    else
	      valid = false;  // if exists change valid to false
	  }
	  //If empty ignore
	}
      }

      // return valid
      return valid;
    }
};
