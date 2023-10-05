public static char closestVowel(String input1, String input2) {
    input1 = input1.toLowerCase(); 
    input2 = input2.toLowerCase();

    String vowels = "aeiou"; 

    if (!input1.contains(input2) || !vowels.contains(input2)) {
        return ' '; 
    }

    int index = input1.indexOf(input2); 

    char nearestVowel = ' ';

    
    for (int i = index - 1; i >= 0 || i < input1.length(); i--) {
        char currentChar = input1.charAt(i);
        if (vowels.contains(String.valueOf(currentChar))) {
            nearestVowel = currentChar;
            break;
        }
    }

    return Character.toUpperCase(nearestVowel); 
}


public static String closestVowel(String input1, String input2) {
    input1 = input1.toLowerCase();
    input2 = input2.toLowerCase();

    String vowels = "aeiou";

    if (!input1.contains(input2) || !vowels.contains(input2)) {
        return " "; 
    }

    int index = input1.indexOf(input2);

    char nearestVowel = ' ';

    for (int i = index - 1; i >= 0 || i < input1.length(); i--) {
        char currentChar = input1.charAt(i);
        if (vowels.contains(String.valueOf(currentChar))) {
            nearestVowel = currentChar;
            break;
        }
    }

    return String.valueOf(Character.toUpperCase(nearestVowel)); 
}
