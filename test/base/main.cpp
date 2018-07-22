#include <gxx/print.h>
#include <g1/tower.h>
#include <g1/indexes.h>

#include <g2/core.h>

void g1_incoming(g1::packet* pack) {
	gxx::println("g1_incoming");
}

int main() {

	g1::incoming_handler = g1_incoming;
	g1::onestep();
}