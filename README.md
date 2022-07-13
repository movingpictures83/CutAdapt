# CutAdapt
# Language: C++
# Input: TXT
# Output: FASTQ
# Tested with: PluMA 1.1, GCC 4.8.4
# Dependencies: CutAdapt 2.6

PluMA plugin to trim adapters using CutAdapt (Martin, 2011).

The plugin accepts as input a TXT file of tab-delimited keyword-value pairs:
fastqfile: Input file of sequences
adapter: Adapter sequence

Trimmed sequences are sent to the output FASTQ.
