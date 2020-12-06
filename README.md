Ticket to Ride AI Player

Game: Ticket to Ride is a board game where you place trains, claiming routes by playing cards, to get from one city to another. The board is essentially a graph with cities as nodes as routes between them as edges. A destination is a goal to connect two specific cities, and completing them is how a player earns points.

Details: I created a simple AI to play the game. It uses Dijkstra's algorithm to determine the shortest route between the two cities it is trying to connect, and tries to play those routes. Because you have to have certain cards to play a route (claim an edge), the edge weights given to Dijkstra's are adjusted each turn. If the AI has all of the cards needed to claim a route, then that route has a smaller edge weight. This influences Dijkstra's to choose routes that it can play instead of saving up cards when it is not needed. Additionally, routes you have already claimed have an edge weight of 0, because they are connected in game.

Shortcomings: It is essentially a greedy algorithm, as it plays whatever route it can in the current shortest path, even if the shortest path may change to make that route obsolete. Because of its greedy nature, it misses many finer points of strategy, such as acquiring similar destinations so claimed routes can overlap, prioritizing almost complete destinations towards the end of the game, and blocking other players' destinations.

Results: Because of these shortcomings, the AI player does not stack up to human players (admittedly ones with experience at the game). However the core gameplay, that of claiming routes between destinations, was roughly at the same level of the human players, despite bizarre looking moves that didn't initially make sense.
