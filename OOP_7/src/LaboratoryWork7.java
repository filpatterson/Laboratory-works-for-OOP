import java.util.*;

public class LaboratoryWork7 {
    public static void main(String[] args) {
        int counterOfSentences = 0;
        int counterLetters = 0;
        int vowels = 0;
        int consonants = 0;
        int count = 0;
        String[] mostUsedWords = new String[5];
        String alphabet = "qwertyuiopasdfghjklzxcvbnm";

        String trimmed;
        int len;    //length of word
        String[] words; //all words

        System.out.println("Enter text :"); //print to console
        Scanner sc = new Scanner(System.in);    //input some data
        String sentence = sc.nextLine();    //read until new line

        sentence = sentence.toLowerCase();  //transform entire string to the low register

        for (int i=0 ; i<sentence.length(); i++) {    //come through entire string
            //Count number of sentences:
            char ch = sentence.charAt(i);   //checks specific symbol
            if(ch == '.' || ch == '?' || ch == '!') {
                counterOfSentences ++;
            }
            else
                //Count number of vowels:
                if(ch == 'a' || ch == 'e' || ch == 'i'
                        || ch == 'o' || ch == 'u') {
                    ++vowels;
                }
                else
                    //Count number of consonants:
                    if((ch >= 'a'&& ch <= 'z')) {
                        ++consonants;
                    }
        }
//  -----------------------------------------------------------------------------------
        //Count number of words
        sentence = sentence.replaceAll("\\p{Punct}", " ");  //replace all non-letter characters
        //and non-digit with whitespaces.
        trimmed = sentence.trim();  //remove the extra space between words
        if (trimmed.isEmpty()) {    //check if there is any value after delete of all whitespaces
            System.out.println(0);  //if null print zero
        } else {
            words = trimmed.split("\\s+");  //count of words splitting into positions where are whitespaces
            len = words.length; //finds amount of words that are in the text
            System.out.println("Number of words: " + len);
        }

        //Count number of letters:
        for (int i = 0; i < sentence.length(); i++){    //come through all text
            for (int j = 0; j < alphabet.length(); j++){    //check entire alphabet
                if (sentence.charAt(i) == alphabet.charAt(j)){
                    counterLetters += 1;
                }
            }
        }

        StringTokenizer t = new StringTokenizer(sentence);  //string tokenizer will split text to the keys, where
                                                            //whitespaces are splitters for those keys
        HashMap<String, Integer> hms = new HashMap<String, Integer>();  //here we make a map of hash, that will use
                                                                        //words as keys for keeping some value of
                                                                        //type integer

        while(t.hasMoreTokens()) {  //checks if there is any more token inside Tokenizer
            String word = t.nextToken();    //go to the next key
            hms.put(word, (hms.get(word) == null ? 1 : hms.get(word) + 1)); //set key in hash map and check if this
                                                                            //word was previously added to the map.
                                                                            //If not, create key and set value 1.
                                                                            //Otherwise add one more to the amount.
        }

        for(String key : hms.keySet()) {    //take first five values from hash map
            if(count < 5){  //global variable that will go through all hash map
                mostUsedWords[count] = key; //get key from hash map
                count++;
            } else
                break;
        }

        for (String key : hms.keySet()) {  // Iterate through hash map
            for(int i = 0; i < 5; i++) {
                boolean ok = true;  //flag that shows if word from hash map isn't already in use inside array
                for (int j = 0; j < 5; j++) {
                    if (key == mostUsedWords[j]) {  //compare with existing values.
                        ok = false;
                        break;
                    }
                }
                if (hms.get(key) > hms.get(mostUsedWords[i]) && ok) {   //if this word isn't already in array and
                                                                        //its value is bigger than in array, then put.
                    mostUsedWords[i] = key;
                    break;
                }
            }
        }

        for(int sort = 0; sort < 3; sort++) {   //sort all words in order from less used to the most used.
            for(int i = 0; i < 4; i++){
                if(hms.get(mostUsedWords[i]) > hms.get(mostUsedWords[i + 1])){
                    String temp = mostUsedWords[i + 1];
                    mostUsedWords[i + 1] = mostUsedWords[i];
                    mostUsedWords[i] = temp;
                }
            }
        }

        System.out.println("\tNumber of letters: " + counterLetters);
        System.out.println("\tNumber of sentences: " + counterOfSentences);
        System.out.println("\tVowels: " + vowels);
        System.out.println("\tConsonants: " + consonants);
        System.out.println("\tRepeated words: " + hms.toString());

        System.out.println("================================================\tTop 5 most used words\t========================================");
        for(int i = 0; i < 5; i++){
            System.out.println(mostUsedWords[i]);
        }
    }
}
