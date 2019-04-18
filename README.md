# Twitter-word-frequency-analyzer
## Description:
Takes the .csv archive provided by Twitter containing every tweet an account has ever sent and returns the frequency of many times words were used in the tweets
## Initial Steps:
- First: Navigate to "settings and privacy" within your Twitter account
- Next:  Click "request archive" to be given an archive of all the tweets sent from your Twitter account
- Next:  Retrieve the tweets.csv file from the archive that is sent to you by Twitter
## Compilation:
- Put the tweets.csv file in the directory with the provided map.cc and reduce.cc files
- Build with command "make build" to use makefile
- If not using makefile build with following command:
   - "g++ -o  map map.cc | g++ -o reduce reduce.cc"
- Compile with the following command:
  - c"at tweets.csv | ./map n | sort | ./reduce | sort -n -k n+1  > tweet_data.txt"
    - n being an integer representing the amount of words in the assocaited n-gram (use 1 for first run)  
  - tweet_data.txt file will be generated containing the associated n-grams and how many times they've been used in your Twitter History!
