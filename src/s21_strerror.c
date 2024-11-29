#include "s21_strerror.h"

/**
 * @brief Returns a string with the error message for the given error number.
 * The error numbers should be in the range 0 to ERR_MSG_AMOUNT - 1.
 * @param errnum The error number.
 * @return A pointer to the error message string. If the error number is out of
 * range, the string "Error number out of range" is returned.
 */
char *s21_strerror(int errnum) {
  char *result = NULL;
  if (errnum < 0 || errnum >= ERR_MSG_AMOUNT) {
    printf("Unknown error: %d", errnum);
    result = "";
  } else {
#ifdef __APPLE__
    result = mac_error_messages[errnum];
#elif defined(__linux__)
    result = linux_error_messages[errnum];
#endif
  }

  return result;
}
