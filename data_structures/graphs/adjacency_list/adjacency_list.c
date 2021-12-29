#include "adjacency_list.h"

graph_t *graph_init(bool directed, int vertices) {
    graph_t *graph = (graph_t *) malloc(sizeof(graph_t));
    assert(graph);

    graph->directed = directed;
    graph->vertices = vertices;

    graph->list = (llist_t *) malloc(sizeof(llist_t) * vertices);

    for (int i = 0; i < vertices; i++) {
        graph->list[i].head = NULL;
    }

    return graph;
}

void graph_destroy(graph_t **graph) {
    for (int i = 0; i < (*graph)->vertices; i++) {
        node_t *curr = (*graph)->list[i].head;
        while (curr != NULL) {
            node_t *next = curr->next;
            free(curr);
            curr = next;
        }
    }

    free((*graph)->list);
    free(*graph);
    *graph = NULL;
}

bool has_vertex(graph_t *graph, unsigned int vertex) {
    return vertex >= 0 && vertex < graph->vertices;
}

bool has_edge(graph_t *graph, unsigned int vertex_1, unsigned int vertex_2) {
    if (has_vertex(graph, vertex_1) && has_vertex(graph, vertex_2) && graph->list[vertex_1].head != NULL) {
        node_t *curr = graph->list[vertex_1].head;
        while (curr->next != NULL) {
            if (curr->val == vertex_2) return true;
            curr = curr->next;
        }

        return false;
    }

    return false;
}

void append_node(graph_t *graph, unsigned int vertex_1, unsigned int vertex_2) {
    node_t *new_node = (node_t *) malloc(sizeof(node_t));
    new_node->val = vertex_2;
    new_node->next = NULL;

    node_t *curr = graph->list[vertex_1].head;
    if (curr == NULL) {
        graph->list[vertex_1].head = new_node;
    } else {
        while (curr->next != NULL) {
            curr = curr->next;
        }

        curr->next = new_node;
    }
}

bool graph_add_edge(graph_t *graph, unsigned int vertex_1, unsigned int vertex_2) {
    if (has_edge(graph, vertex_1, vertex_2))
        return false;

    append_node(graph, vertex_1, vertex_2);
    if (!graph->directed)
        append_node(graph, vertex_2, vertex_1);

    return true;
}

bool delete_node(graph_t *graph, unsigned int vertex_1, unsigned int vertex_2) {
    node_t **head = &graph->list[vertex_1].head;
    node_t *temp = *head;

    if (temp != NULL && temp->val == vertex_2) {
        printf("deleting %d\n", temp->val);
        (*head) = temp->next;
        free(temp);
    } else {
        node_t *prev;
        while (temp != NULL && temp->val != vertex_2) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == NULL)
            return false;

        prev->next = temp->next;
        free(temp);
    }

    return true;
}

bool graph_delete_edge(graph_t *graph, unsigned int vertex_1, unsigned int vertex_2) {
    if (!has_edge(graph, vertex_1, vertex_2))
        return false;

    bool retval = delete_node(graph, vertex_1, vertex_2);
    if (!graph->directed)
        retval = delete_node(graph, vertex_2, vertex_1);

    return retval;
}

void graph_print_list(graph_t *graph) {
    for (int i = 0; i < graph->vertices; i++) {
        printf("(%d -> ", i);

        node_t *curr = graph->list[i].head;
        while (curr != NULL) {
            printf("%d) ", curr->val);
            curr = curr->next;
            if (curr) printf("(%d -> ", i);
        }

        printf("\n");
    }

    printf("\n");
}
