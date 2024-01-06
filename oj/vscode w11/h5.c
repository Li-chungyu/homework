/*************************************************************
function name: convertToDifferentBase
description: Convert a decimal number @dec to the number with different @base and store the result as a string in result
return vaule: Result after convert.
notice: The letter you see in the number should be upper case.
*************************************************************/
char *convertToDifferentBase(int dec, int base, char *result) {
	if (dec < base) {
        if(dec<10){
            result[0] = dec+'0';
        }else{
            result[0] = dec-10+'A';
        }
        result[1] = '\0';
        return result;
    }
  	int remainder = dec % base;
    char remainderChar;
	if (remainder < 10) {
        remainderChar = remainder + '0';
    } else {
        remainderChar = remainder - 10 + 'A';
    }
  	convertToDifferentBase(dec / base, base, result);
	int length = strlen(result);
    result[length] = remainderChar;
    result[length + 1] = '\0';

    return result;
}
