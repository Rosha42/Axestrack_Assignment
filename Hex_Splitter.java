import java.util.*;
import java.lang.*;
import java.io.*;
public class Hex_Splitter  {

static String start_hex="0x90 0x00";
static String delimiter="0x0d 0x0a";

public static int Hex2decimal(String s) {
             String digits = "0123456789abcdef";
             s = s.toLowerCase();
             int val = 0;
             for (int i = 0; i < s.length(); i++) {
                 char c = s.charAt(i);
                 int d = digits.indexOf(c);
                 val = 16*val + d;
             }
             return val;
         }
public static String[] Hex_Stream(String start,String end,String s)
{	 
    String a[]=new String[13];
	int index=0;
    int i=0; int position=0;
   while(i<s.length())
   {
	   int j=0;String Hex_start="",Hex_end="";
	   while (j<start.length())
	   {
		   Hex_start=Hex_start+s.charAt(i++);
		   j++;
	   }       
	  if((start).equals(Hex_start))
	   {
		   String Hex_len=String.valueOf(s.charAt(i++));
		   Hex_len=Hex_len+s.charAt(i++);
		   int Dec_length = Hex2decimal(Hex_len.toString());
		   i+=Dec_length*2;
	   }
		j=0;   
	   while (j<end.length())
	   {
		   Hex_end=Hex_end+s.charAt(i++);
		   j++;
	   }
		if((end).equals(Hex_end))
		{
			if(i==s.length()-1)
			a[index]=s.substring( position,i-1); 
			else
			a[index++]=s.substring( position,i );	
		}
		
	position =i;
    }
	return a;
}


	
public static void main(String[] args) 
{
	String s="90000d01035889905270194601894e590d0a90000a134406040002018b8f5e0d0a90001f12100c1b060a17ca033619bc086213e016554701946100c90032fc017c8b6e0d0a90001f12100c1b060a21ca03361cf8086211a012554901946100c90032fc017da1e60d0a90001f12100c1b060a2bc80336206408620f201a554701946100c90078d4017e07d80d0a90001f12100c1b060a35c9033623a408620cb015554801946100c90078d4017f73470d0a90001f12100c1b060b03c90336265c08620ad00e554901946100c90078d4018079a40d0a90001f12100c1b060b17c903362840086208900f552101946100c90078d40183de740d0a90001f12100c1b060b21c903362bbc086205201e553701946100c90078d4018411c50d0a90001f12100c1b060b2bc903362e3c086202700c554001946100c90078d40185fd5a0d0a90001f12100c1b060b35c903363050086200a00f554501946100c900a840018742d80d0a90001f12100c1b060c11c90336313c0861ff8000553101946100c900a840018ac61b0d0a90002516100c1b060c1ec90336313c0861ff800055310901946100c900a8404406040e02018c6edf0d0a";
	String[] start_hex1=start_hex.split("0x| ");
	String start=start_hex1[1]+start_hex1[3];
	String[] end_array=delimiter.split("0x| ");
	String end=end_array[1]+end_array[3];

try {
String[] Ans=Hex_Stream(start,end,s);
for(String str : Ans)
System.out.println(str);
} catch(Exception e) {
         System.out.println("ERROR ARRAY OUT OF BOUND");
    }
	
	 
}
}