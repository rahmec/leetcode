# H-index (274)

Given an array of integers citations where citations[i] is the number of citations a researcher received for their ith paper, return the researcher's h-index.

According to the definition of h-index on Wikipedia: The h-index is defined as the maximum value of h such that the given researcher has published at least h papers that have each been cited at least h times.

## Reasoning

An immediate solution for me is sorting the array in n\*log(n) and then traverse it from the end to find h-index as a check between value and index. This is an n\*log(n) solution that seems reasonable;  

Let's apply a merge-sort or quick-sort and try it.

Ok, this works, but h-index calculation is a little bit more complex than this. 

Basically it depends on number of citations and number of papers with more citations;

We assume there might be 0 papers or 0 citations per paper, so we start with 0.

At this point, if a paper has an y h-index and there at least y more papers (considering it's sorted) than y is the new h-index.
But this is not just it, it's also about the remaining papers.
y is higher than the remaining papers z, than we know that z papers has at least y.
So z is a possible h-index. 
So we use a candidate and set it if it's higher than current calculated h-index.

Put in a synthetic way, the candidate is the minimum between remaining papers and the number of citations.
H-index is the maximum between current h-index and the candidate.

This is my first solution, an O(n\*log(n)) one.
Can it be improved? Well, there's the basic rule: if it does more than required, very probably it can be.

Matter of fact, this can be done in O(n) time.
The logic is: we know h-index is between 0 and n. 
Traverse it once and use an array to keep track of number of papers with i citations.
Than traverse the new array from the end and cumulative sum the papers until the sum is higher than the number of citations i checking. 

## Code 

### First solution (O(n\*log(n))

'''
void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int* array, int low, int high){
    int pivot = array[high];
    int i = (low - 1);

    for(int j=low; j<=high-1; j++){
        if(array[j] < pivot){
            i++;
            swap(&array[i], &array[j]);
        }
    }

    i++;

    swap(&array[i], &array[high]);
    return i;
}

void quickSort(int* array, int low, int high){
    if(low < high){
        int pivot = partition(array, low, high);

        quickSort(array, low, pivot-1);
        quickSort(array, pivot+1, high);
    }
}

int hIndex(int* citations, int citationsSize) {
    
    quickSort(citations, 0, citationsSize-1);

    for(int i=0; i<citationsSize; i++){
        if(n-i <= citationsSize[i])
            return n-i;
    }

    return 0;
    
}
'''

### Second solution (O(n))

'''
int hIndex(int* citations, int citationsSize) {
    
    int papers_per_cit[citationsSize+1];

    for(int i = 0; i<citationsSize+1; i++){
        papers_per_cit[i]=0;
    }

    for(int i = 0; i<citationsSize; i++){
        if(citations[i]>=citationsSize){
            papers_per_cit[citationsSize]++;
        }else{
            papers_per_cit[citations[i]]++;
        }
    }

    int cum_papers_sum = 0;
    for(int i = citationsSize; i>=0; i--){
        cum_papers_sum += papers_per_cit[i];
        if(cum_papers_sum >= i){
            return i;
        }
    }

    return 0;
    
}
'''
