struct DisjointSet {
	vector<int> parent, counts;
	DisjointSet(int _size) : parent(_size), counts(_size) {
		for (int i = 0; i < _size; ++i) {
			parent[i] = i;
		}
	}

	// Find parent's node
	int p_lookup(int u) {
		if (u == parent[u]) {
			return u;
		}

		return parent[u] = p_lookup(parent[u]);
	}

	// Join nodes
	void join(int u, int v) {
		u = p_lookup(u);
		v = p_lookup(v);

		if (u != v) {
			if (counts[u] < counts[v]) {
				swap(u, v);
			}

			counts[u] += counts[v];
			parent[v] = u;
		}
	}
};
