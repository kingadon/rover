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
extern const size_t MAX_BYTES;

/** @brief Maximum bytes to reserve for paths to components. */
extern const size_t MAX_PATH_BYTES;

/** @brief Root directory of components. */
extern const char* const ROOT_COMPONENT_DIR;

/** @brief Format string for snprintf to build path. */
extern const char* const PATH_FMT;

/** End global constants. */

/**
 * @brief Write a string into file specified by path.
 * @param path Absolute path to the file.
 * @param fmt String value to be written.
 * @param val String value to be written.
 * @return Return the number of elements written or -1 if error.
 */
extern int rvrWrite(const char* path, const char* fmt, struct rvrvalue* val);

/**
 * @brief Write an integer as string into file specified by path.
 * @param path Absolute path to the file.
 * @param val Integer value to be written.
 * @return Return the number of elements written or -1 if error.
 */
extern int rvrWriteInt(const char* path, int val);

/**
 * @brief Write an unsigned integer as string into file specified by path.
 * @param path Absolute path to the file.
 * @param val Unsigned integer value to be written.
 * @return Return the number of elements written or -1 if error.
 */
extern int rvrWriteUInt(const char* path, size_t val);


#endif