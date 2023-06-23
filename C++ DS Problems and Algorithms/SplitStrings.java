import java.util.*;

public class SplitStrings
{
	public static void main(String args[])
	{
		String text = "ram@gmail.com";
		String vowels = "a::b::c::d:e";

		String res1[] = text.split(" ");
		String res[] = text.split("\\@");
		String[] result = vowels.split("::");

		
		for(String str:res)
			System.out.print(str+" ");
	}
}