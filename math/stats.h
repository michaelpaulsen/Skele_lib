#include <cstdint>
#pragma warn('use stats.hpp instead'); 

///converted from java script by Michael Paulsen 
///@author adamnovak
///see https://gist.github.com/adamnovak/f34e6cf2c08684752a9d
namespace Skele_lib {
	namespace Math {
		namespace stats {
			//enter with successesAvailable<popSize/2 and sampled<popSize/2

			double hyp(int popSize, int successesAvailable, int sampled, int successesObserved ){
				int smallerSet, largerSet;
				// The actual hypergeometric CDF. Requires that half or less of the
				// population be successes, and that half or less of the population be
				// sampled.
				// We conceptualize the problem like this: given the population, choose the
				// successes, choose the sampled items, and look at the size of the overlap.
				// Because of this, it doesn't matter which set is the successes and which
				// is the sampled items, so we can swap those around for numerical reasons.
				// What are the sizes of the two sets we are intersecting, identifgied by
				// relative size?


				// best to have sampled<successesAvailable
				if (successesAvailable < sampled) {
					// The set of successes is smaller
					smallerSet = successesAvailable;
					largerSet = sampled;
				}
				else {
					// The set of sampled items is smaller
					smallerSet = sampled;
					largerSet = successesAvailable;
				}

				// This is an intermediate value I don't really understand, which is used in
				// the middle of the cumulative CDF calculation.
				double h = 1;
				// This is the probability of having observed everything we looked at so
				// far. Except sometimes it goes above 1 and we have to fix it?
				double s = 1;
				// This is an index over which item we are at in the smaller set
				double k = 0;

				// This is an index over which item we are at in the intersection
				double i = 0;
				while (i < successesObserved) {
					// For each item in the intersection    

					while (s > 1 && k < smallerSet) {
						// Sample some items from the smaller set (?)

						// Get the probability of, after already grabbing k items for the
						// smaller set that weren't in the larger set, grabbing another
						// item for the smaller set that wasn't in the larger set.

						// Then multiply h and s by this probability

						h = h * (1 - largerSet / (popSize - k));
						s = s * (1 - largerSet / (popSize - k));

						// Advance to the next item in the smaller set.
						k = k + 1;
					}

					// Get the number of things not taken for the intersection, after taking
					// this thing: (popSize - smallerSet - largerSet + i + 1)

					// Get the number of things in the smaller set not in the intersection,
					// and multiply by the number of things in the larger set not in the
					// intersection.

					// As i goes from 0 to successesObserved, h accumulates:
					// factors of smallerSet to smallerSet - successesObserved on top
					// factors of largerSet to largerSet - successesObserved on top
					// factors of 1 to successesObserved on bottom
					// factors of (popSize - smallerSet - largerSet + 1) to 
					//    (popSize - smallerSet - largerSet + successesObserved)

					// I'm not entirely sure how this works, but it looks like we're
					// cheating a bit to calculate the sum of ratios of factorials without
					// needing to re-do lots of the multiplications.

					h = h * (smallerSet - i) * (largerSet - i) / (i + 1) / (popSize - smallerSet - largerSet + i + 1);
					s = s + h;

					// Move on to the next item in the intersection
					i = i + 1;
				}

				while (k < smallerSet) {
					// For each remaining item in the smaller set (conceptually the sampled
					// ones) that was not part of the intersection(?)

					// popSize - k is the number of items remaining to be grabbed for the
					// smaller set.

					// largerSet / (popSize - k) is the probability that the next item
					// grabbed for the smaller set would be in the larger set.

					// We take 1 - that because we know the next item grabbed for the
					// smaller set will not have been in the larger set, since it wasn't in
					// the intersection.

					// Then we multiply the probability of everything we've seen so far by
					// the probability of having successfully not added some extra thing to
					// our intersection.
					s = s * (1 - largerSet / (popSize - k));

					// Move on to grab the next item in the smaller set.
					k = k + 1;
				}
				return s;
			};

		}
	}
}
//