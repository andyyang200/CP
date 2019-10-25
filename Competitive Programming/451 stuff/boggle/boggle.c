/* Author: Senyu Tong
 * id: senyut
 * 15-451 HW3 PG
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>

int row, col, layer;
int res = 0;
char word[10001];
/* right, down, left, up */
int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
/* node_type = True: orginal node, multiple in, only one out to duplicated node
 *             False: duplicated node. only one 1, multiple out to original nodes
 */
typedef struct node_header node;
struct node_header {
    int layer_num;
    bool node_type;   // original node or duplicated node
    node *out[5];    // out nodes
    node *in[5];     // in nodes
    bool fwd[5];     // right, down, left, up, to_duplicated
    bool back[5];
    bool visited;
};

/* return if the index is in the grid */
bool in_grid(int r, int c) {
    return c >= 0 && c < col && r >= 0 && r < row;
}


node *make_node(int this_layer, int i, int j) {
    node *this_node = (node *)malloc(sizeof(node));
    node *dup_node = (node *)malloc(sizeof(node));
    this_node->layer_num = this_layer;
    dup_node->layer_num = this_layer;
    this_node->node_type = true;
    dup_node->node_type = false;
    for (int i = 0; i < 5; i++) {
        this_node->out[i] = NULL;
        this_node->in[i] = NULL;
        dup_node->out[i] = NULL;
        dup_node->in[i] = NULL;
        this_node->fwd[i] = false;
        this_node->back[i] = false;
        dup_node->fwd[i] = false;
        dup_node->back[i] = false;
    }
    this_node->out[4] = dup_node;
    this_node->fwd[4] = true;
    dup_node->in[4] = this_node;
    return this_node;
}

int opposite(int dir) {
    if (dir == 4) return 4;
    return (dir + 2) % 4;
}

bool DFS(node *v) {
    v->visited = true;
    if (v->layer_num == layer - 1 && !v->node_type) {
        res += 1;
        v->visited = false;
        return true;
    }
    for (int i = 0; i < 5; i++) {
        if (v->fwd[i]) {
            node *next = v->out[i];
            if (!next->visited) {
                next->visited = true;
                if (DFS(next)) {
                    next->back[opposite(i)] = true;
                    v->fwd[i] = false;
                    v->visited = false;
                    return true;
                }
            }
        }
        if (v->back[i]) {
;
            node *prev = v->in[i];
            if (!prev->visited) {
                prev->visited = true;
                if (DFS(prev)) {
                    v->in[i]->fwd[opposite(i)] = true;
                    v->back[i] = false;
                    v->visited = false;
                    return true;
                }
            }
        }
    }
    //v->visited = false;
    return false;
}



int main() {
    /* READ DATA */
    scanf("%s\n", word);
    scanf("%d%d\n", &row, &col);

    layer = strlen(word);
    int letter_count = 0;

    /* form grid and add counter */
    int map[row][col];
    node ***graph = (node ***)malloc(sizeof(node **) * row);
    for (int i = 0; i < row; i++) {
        graph[i] = (node **)malloc(sizeof(node *) * col);
        for (int j = 0; j < col; j++) {
            graph[i][j] = NULL;
            char c;
            if (j == col - 1 && i != row - 1) scanf("%c\n", &c);
            else scanf("%c", &c);
            map[i][j] = -1;
            for (int k = 0; k < layer; k++) {
                if (c == word[k]) {
                    map[i][j] = k;
                    if (k == 0) letter_count += 1;
                }
            }
        }
    }

    int idx[layer];
    for (int i = 0; i < layer; i++) {
        idx[i] = 0;
    }
    node **start = (node **)malloc(sizeof(node *) * letter_count);
    int s_i = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            int this_layer = map[i][j];
            if (this_layer == -1) continue;
            node *this_node = graph[i][j];
            if (!this_node) {
                this_node = make_node(this_layer, i, j);
                graph[i][j] = this_node;
            }
            if (this_layer == 0)
                start[s_i++] = this_node;


            for (int k = 0; k < 4; k++) {
                int next_i = i + dirs[k][0];
                int next_j = j + dirs[k][1];
                if (in_grid(next_i, next_j)) {
                    int next_layer = map[next_i][next_j];
                    if (next_layer == -1)
                        continue;
                    node *next_node = graph[next_i][next_j];
                    if (!next_node) {
                        next_node = make_node(next_layer, next_i, next_j);
                        graph[next_i][next_j] = next_node;
                    }


                    if (next_layer == this_layer || next_layer == this_layer+1) {
                        node *dup = this_node->out[4];
                        assert(!dup->node_type);
                        dup->out[k] = next_node;
                        dup->fwd[k] = true;
                        next_node->in[opposite(k)] = dup;
                    }
                }
            }
        }
    }

    bool used_first[letter_count];
    for (int i = 0; i < letter_count; i++) {
        used_first[i] = false;
    }
    while (true) {
        bool flag = false;
        for (int i = 0; i < letter_count; i++) {
            if (!used_first[i]) {
                used_first[i] = true;
                if (DFS(start[i])) {
                    flag = true;
                }
            }
        }
        if (!flag) break;
    }
    printf("%d\n", res);

    return 0;

}
/*
goat
4 4
.g..
goat
oat.
at..

*/
