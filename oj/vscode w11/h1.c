#include<stdlib.h>
/*******************************************
function name: replace
description: When mode is 1, replace the first target finded in source with the replacement.
             When mode is 2, replace left-most target by replacement until there are no targets in the source.
return value: Return the result after replace.
*******************************************/
char *replace(char *source, char *target, char *replacement, int mode) {
  // 模式為1時，只替換第一個目標
  if (mode == 1) {
    char *found = strstr(source, target);
    if (found != NULL) {
      // 複製替換值前的部分
      size_t prefix_length = found - source;
      char *result = malloc(strlen(source) - strlen(target) + strlen(replacement) + 1);
      strncpy(result, source, prefix_length);


      // 附加替換值
      strcat(result, replacement);

      // 附加剩餘部分
      strcat(result, found + strlen(target));
      free(result);
      return result;
    }
  }
  // 模式為2時，一直替換左邊的目標，直到源字串中不再有目標
  else if (mode == 2) {
    char *found = strstr(source, target);
    while (found != NULL) {
      // 複製替換值前的部分
      size_t prefix_length = found - source;
      char *result = malloc(strlen(source) - strlen(target) + strlen(replacement) + 1);
      strncpy(result, source, prefix_length);


      // 附加替換值
      strcat(result, replacement);

      // 附加剩餘部分
      strcat(result, found + strlen(target));

      // 更新 source
      strcpy(source, result);

      free(result);
      // 重新搜尋目標
      found = strstr(source, target);
    }
    return source;
  }
}