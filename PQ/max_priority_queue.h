#include<vector>
using namespace std;

class priorityQueue {
        vector<int> pq;
    public:
        priorityQueue() {
        }

        int getSize() {
            return pq.size();
        }

        bool isEmpty() {
            return pq.size()==0;
        }

        int getMax() {
            if(isEmpty()) return 0;
            else          return pq[0];
        }

        void insert(int val) {
            pq.push_back(val);
            int cI = pq.size()-1;
            while(cI>0) {
                int pI = (cI-1)/2;
                if(pq[pI]<pq[cI]) {
                    int temp = pq[pI];
                    pq[pI]   = pq[cI];
                    pq[cI]   = temp;
                } else {
                    break;
                }
                cI = pI;
            }
        }

        int removeMax() {
            int ans = pq[0];
            pq[0]   = pq[pq.size()-1];
            pq.pop_back();
            int pI = 0;
            int lcI = 2*pI+1;
            int rcI = 2*pI+2;
            while(lcI<pq.size()) {
                int maxI=pI;
                if(pq[pI]<pq[lcI]) maxI = lcI;  
                if(pq[pI]<pq[rcI]) maxI = rcI;  
                if(pI == maxI) break;
                else {
                    int temp = pq[pI];
                    pq[pI] = pq[maxI];
                    pq[maxI] = temp;
                }
                pI = maxI;
                lcI = 2*pI+1;
                rcI = 2*pI+2;
            }
            return ans;
        }
};