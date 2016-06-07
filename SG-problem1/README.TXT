////////////////////////////////////////////////////////////////////////////////
// Paul Ledeboer
// 6/7/2016
// Programming problem for Scientific Games Interactive
//
// Problem 1:
// Description
// Given a list of people with their birth and end years (all between 1900 and
// 2000), find the year with the most number of people alive.
//
// Code
// Solve using a language of your choice and dataset of your own creation.
//
// Submission
// Please upload your code, dataset, and example of the program’s output to Bit
// Bucket or Github. Please include any graphs or charts created by your program.
////////////////////////////////////////////////////////////////////////////////
// Assumptions:
// - Data with birth year prior to 1900, death year after 2000,
//   or death year less than birth year is discarded.
// - Program prints the FIRST year with the most number of alive
//   people. Does NOT report subsequent years having the same number.
////////////////////////////////////////////////////////////////////////////////
// Discussion:
//
// First thought was to brute-force create an array of years from 1900 to 2000
// and then for each data set increment the array range of people alive between
// that birth and death value. After more thought, realized the specific sets
// don't matter, so chose to create a list of birth years and death years.
// Then for each year, add the births and decrement the deaths while tracking
// the largest year. Once you are out of births, no need to continue.
//
// I chose to use priority_queue structures sorted backwards to keep track of
// the birth and death years because it was straightforward. Each insertion is
// sorted, so there is some performance penalty from that. You could add them to
// an unsorted list and then sort once at the end for some performance savings.
////////////////////////////////////////////////////////////////////////////////
// Data files:
// - birth-death-data.csv
//   I created this file from http://www.dobsearch.com/death-records/ which will
//   give you up to 100 records of birth date/death date results for a given
//   name search. It does contain some invalid values with birth prior to 1900
//   or death after 2000.
//
// - test-data.csv
//   Small test file with just a few valid records for initial testing.
//
// - bad-data.csv
//   This contains only invalid data so I could test discarding bad data plus
//   handling a file with no valid records.
//
// - birth-death-clean-data.csv
//   Changed any dates prior to 1900 to be 1900 and anything after 2000 to be
//   2000 so it has no invalid data. Still had the same result, interestingly.
////////////////////////////////////////////////////////////////////////////////
