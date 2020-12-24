/* Copyright (c) 2019-2021 Grant Hadlich
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the Software), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED AS IS, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */
/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char *buf4);
 */

struct Node {
    struct Node* next;
    char val;
};

struct Queue {
    struct Node* head;
    struct Node* tail;
    long size;
};

static struct Queue q;

int q_size() {
    return q.size;
}

void q_enqueue(char x) {
    struct Node* current = (struct Node*)calloc(1, sizeof(struct Node));
    current->val = x;
    if (q.head == NULL) {
        q.head = current;
        q.tail = current;
    }
    else {
        q.tail->next = current;
        q.tail = current;
    }
    
    q.size++;
}

char q_dequeue() {
    if (q.size == 0) return '\0';
    struct Node* current = q.head;
    char ret = current->val;
    q.size--;
    q.head = current->next;
    free(current);
    
    return ret;
}

int init = 0;

/**
 * @param buf Destination buffer
 * @param n   Number of characters to read
 * @return    The number of actual characters read
 */
int _read(char* buf, int n) {
    
    if (buf == NULL || n <= 0) {
        return 0;
    }
    
    q.size = 0;
    q.head = NULL;
    q.tail = NULL;
    
    buf[0] = '\0';
    
    int bytesRead = 0;
    
    while (bytesRead < n) {
        if (q_size() == 0) {
            char temp[4];
            int byteCount = read4(temp);
            printf("byteCount: %d\n", byteCount);
            
            if (byteCount <= 0) {
                printf("Breaking\n");
                break;
            }
            for (int i = 0; i < byteCount; i++) {
                q_enqueue(temp[i]);
            }
        }
        else {
            buf[bytesRead++] = q_dequeue();
        }
    }
    
    printf("bytesRead:%d\n", bytesRead);
    
    return bytesRead;
}