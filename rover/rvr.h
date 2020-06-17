/**
 * @file rvr.h
 * @author Kingston A Huynh
 * @date June 16 2020
 * @brief File contains general utility functions and constants used thru out library.
 */

#ifndef RVR_H
#define RVR_H

/** Put global constants here. */
/** @brief Maximum bytes to reserve for writing values to component attributes. */
extern size_t MAX_BYTES;

/** @brief Maximum bytes to reserve for paths to components */
extern size_t MAX_PATH_BYTES;

/** End global constants. */

/**
 * @brief Write a string into file specified by path.
 * @param path Absolute path to the file.
 * @param data String value to be written.
 * @return Return the number of elements written or -1 if error.
 */
extern int rvr_write(const char* path, char* data);

/**
 * @brief Write an unsigned integer as string into file specified by path.
 * @param path Absolute path to the file.
 * @param data Unsigned integer value to be written.
 * @return Return the number of elements written or -1 if error.
 */
extern int rvr_write_uint(const char* path, size_t val);


#endif