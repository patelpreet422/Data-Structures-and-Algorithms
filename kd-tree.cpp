#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

class Node {
public:
    std::vector<double> point;
    Node *left, *right;
    Node(const std::vector<double> &point) : point(point), left(nullptr), right(nullptr) {}
};

class KdTree {
public:
    Node *root;
    KdTree(const std::vector<std::vector<double>> &points) {
        root = build_tree(points, 0);
    }

    // insert a new point into the tree
    void insert(const std::vector<double> &point) {
        insert_helper(root, point, 0);
    }

    // search for the nearest neighbor to a given point
    Node *nearest_neighbor(const std::vector<double> &point) {
        return nearest_neighbor_helper(root, point, 0);
    }

private:
    Node *build_tree(std::vector<std::vector<double>> points, int depth) {
        int axis = depth % points[0].size();
        if (points.empty()) {
            return nullptr;
        }

        if(points.size() == 1) {
            return new Node(points[0]);
        }

        int mid = points.size() / 2;
        std::nth_element(points.begin(), points.begin() + mid, points.end(), [axis](std::vector<double> a, std::vector<double> b) {
            return a[axis] < b[axis];
        });
        Node *node = new Node(points[mid]);
        node->left = build_tree(std::vector<std::vector<double>>(points.begin(), points.begin() + mid), depth + 1);
        node->right = build_tree(std::vector<std::vector<double>>(points.begin() + mid, points.end()), depth + 1);
        return node;
    }

    void insert_helper(Node *node, const std::vector<double> &point, int depth) {
        int axis = depth % point.size();
        if (point[axis] < node->point[axis]) {
            if (!node->left) {
                node->left = new Node(point);
            } else {
                insert_helper(node->left, point, depth + 1);
            }
        } else {
            if (!node->right) {
                node->right = new Node(point);
            } else {
                insert_helper(node->right, point, depth + 1);
            }
        }
    }

    Node *nearest_neighbor_helper(Node *node, const std::vector<double> &point, int depth) {
        if (!node) {
            return nullptr;
        }
        int axis = depth % point.size();
        Node *best = node;
        double best_distance = distance(point, node->point);
        double threshold = point[axis] - node->point[axis];
        if (threshold < 0) {
            Node *neighbor = nearest_neighbor_helper(node->left, point, depth + 1);
            if (neighbor) {
                double neighbor_distance = distance(point, neighbor->point);
                if (neighbor_distance < best_distance) {
                    best = neighbor;
                    best_distance = neighbor_distance;
                }
            }
        }
        if (threshold >= 0) {
            Node *neighbor = nearest_neighbor_helper(node->right, point, depth + 1);
            if (neighbor) {
                double neighbor_distance = distance(point, neighbor->point);
                if (neighbor_distance < best_distance) {
                    best = neighbor;
                    best_distance = neighbor_distance;
                }
            }
        }
        if (abs(threshold) < best_distance) {
            Node *neighbor = nearest_neighbor_helper(threshold < 0 ? node->right : node->left, point, depth + 1);
            if (neighbor) {
                double neighbor_distance = distance(point, neighbor->point);
                if (neighbor_distance < best_distance) {
                    best = neighbor;
                    best_distance = neighbor_distance;
                }
            }
        }
        return best;
    }

    double distance(const std::vector<double> &a, const std::vector<double> &b) {
        double sum = 0;
        for (int i = 0; i < a.size(); ++i) {
            sum += (a[i] - b[i]) * (a[i] - b[i]);
        }
        return sqrt(sum);
    }
};

int main() {
    std::vector<std::vector<double>> points = {{1, 1}, {10, 10}};

    KdTree tree(points);

    // for(int i = 1; i <= 10; ++i) {
        vector<double> query = {7, 5};
        std::vector<double> nearest_neighbor = tree.nearest_neighbor(query)->point;
        std::cout << "Nearest neighbor to (" << query[0] << ", " << query[1] << ") is (" << nearest_neighbor[0] << ", " << nearest_neighbor[1] << ")" << std::endl;
    // }

    return 0;
}


