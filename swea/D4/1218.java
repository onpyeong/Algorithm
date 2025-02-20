import java.util.*;
import java.io.*;

class Solution {
    
    static int isValid;
    static int types[] = new int[4]; //'(', '[', '{', '<'
    
    static void init() {
    	for(int i = 0; i < 4; i++) {
        	types[i] = 0;
        }
        isValid = 1;
    }
    
	public static void main(String args[]) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        
        int T = 10;
        int N;
        char c;
        String line;
        
        for(int t = 1; t <= T; t++) {
            N = Integer.parseInt(br.readLine());
        	line = br.readLine();
            init();
            if(line.length() % 2 == 0) {
                for(int i = 0; i < line.length(); i++) {
                    c = line.charAt(i);
                    if(c == '(') {
                        types[0]++;
                    }else if(c == ')') {
                        types[0]--;
                    }else if(c == '[') {
                        types[1]++;
                    }else if(c == ']') {
                        types[1]--;
                    }else if(c == '{') {
                        types[2]++;
                    }else if(c == '}') {
                        types[2]--;
                    }else if(c == '<') {
                        types[3]++;
                    }else {
                        types[3]--;
                    }
                }
                for(int j = 0; j < 4; j++) {
                    if(types[j] != 0) {
                        isValid = 0;
                        break;
                    }
                }
            }else {
            	isValid = 0;
            }
            sb.append("#" + t + " " + isValid + "\n");
        }
        System.out.println(sb);
    }
}
