class adj_list:
    def __init__(self):
        self.adj_dict = {}

    def add_edge(self, v1, v2, w):
        edge_tuple = (v2, w)
        if self.adj_dict[v1]:
            if edge_tuple not in self.adj_dict[v1]:
                self.adj_dict[v1].append(edge_tuple)
        else:
            self.adj_dict[v1] = []
            self.adj_dict[v1].append(edge_tuple)

    def get_adjacency_list(self):
        return self.adj_dict


def construct_vertical_list(list_of_lists):

    n_lists = len(list_of_lists)
    vert_list = [[] for _ in range(n_lists)]

    for row in list_of_lists:
        for i, el in enumerate(row):
            vert_list[i].append(el)

    return vert_list


def get_adj_list_from_grid(grid_list):
    gr_adj_list = adj_list()

    for i, row in enumerate(grid_list):
        l_row = len(row)
        for y, val in enumerate(row):
            ind = i*l_row + y
            gr_adj_list.add_edge()

    return gr_adj_list
