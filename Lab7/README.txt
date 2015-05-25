// Name: Crystal Lim
// SID: 861041326
// Date: 5/18/15
// Lab 7
// Section 21

PART B.

-------------------------------------------------------------------------------
Make lists of the advantages and disadvantages of trees and hash tables.
(at least these implementations)

___TREES___
ADV:
- once inserted, item is faster to find
- don't have unused buckets
- even distribution
- provides storage in key order

DISADV:
- time per query larger than hash table => less efficient, lower performance
- from our graph, performance slows as more words are added
- slower when more items with same key
- takes extra time to balance




___HASH TABLES___
ADV:
-time per query smaller than trees => more effecient, higher performance
-once inserted, item is faster to find
-from our graph, performance stays about the same for increasing amount of words

DISADV:
-can have unused buckets
-if items have uneven amount of similar values, storage can be very unbalanced
and inefficient
- do not provide storage in key order

-------------------------------------------------------------------------------

What else would you like to be able to measure to compare the two data
structures

I would like to measure performance with values other than strings, and with 
data that produces a lot of values with the same key or data that is very
spread out, like several small values and a lot of large values that have the
same key. So this time we did Time vs Number of Words.  We could then do
Time vs. Spread of Words. I would also like to look at overall time instead of
time per word as we did.