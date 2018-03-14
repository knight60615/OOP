import java.io.*;
import java.util.Scanner;
public class oop1 {
		public static void main(String args[]) throws IOException{
				int len,i=0;
				int[] number = new int[50];
				BufferedReader buf = new BufferedReader(new InputStreamReader(System.in));
				while(true){
						i=0;
						System.out.println("Please input your expression:");
						String str=buf.readLine();
						len=str.length();
						//if(str[len-1]=='\n'){str[len-1]=0}
						String[] tokens = str.split(" ");
						for(String token:tokens) { 
								if(token.compareTo("+")==0){
										number[i-2]=number[i-2]+number[i-1];
										i--;
								}
								else if(token.compareTo("-")==0){
										number[i-2]=number[i-2]-number[i-1];
										i--;
								}
								else if(token.compareTo("*")==0){
										number[i-2]=number[i-2]*number[i-1];
										i--;
								}
								else if(token.compareTo("/")==0){
										number[i-2]=number[i-2]/number[i-1];
										i--;
								}
								else if(token.compareTo("%")==0){
										number[i-2]=number[i-2]%number[i-1];
										i--;
								}
								else if(token.compareTo("^")==0){
										double temp=Math.pow(number[i-2],number[i-1]);
										number[i-2]=(int)temp;
										i--;
								}
								else{
										number[i] = Integer.parseInt(token);
										i++;
								}
						}
						System.out.println("Answer is: " +number[0]);
						System.out.println("Continue? (Y/N)");
						str=buf.readLine();
						if(str.compareTo("Y")==0||str.compareTo("y")==0)
								continue;
						else
								break;
				}
		} // end main
} // end of class oop1
