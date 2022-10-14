struct DisjointSet {
	vector<int> parent, counts;
	DisjointSet(int _size) : parent(_size), counts(_size) {
		for (int i = 0; i < _size; ++i) {
			parent[i] = i;
		}
	}

	int p_lookup(int u) {
		if (u == parent[u]) {
			return u;
		}

		return parent[u] = p_lookup(parent[u]);
	}

	bool join(int u, int v) {
		u = p_lookup(u);
		v = p_lookup(v);

		if (u == v) {
			return false;
		}

		if (counts[u] < counts[v]) {
			swap(u, v);
		}

		counts[u] += counts[v];
		parent[v] = u;
		return true;
	}
};

struct Edge {
	int u, v, w;
};

int minimum_spanning_tree(vector<Edge> edges) {
	sort(edges.begin(), edges.end(), [&](const Edge& shl, const Edge& shr) {
		return shl.w < shr.w;
	});

	DisjointSet dset(edges.size());

	int total_weight = 0;
	for (Edge edge : edges) {
		if (dset.join(edge.u, edge.v)) {
			total_weight += edge.w;
		}
	}

	return total_weight;
}
