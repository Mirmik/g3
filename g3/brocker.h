#ifndef G3_BROCKER_H
#define G3_BROCKER_H

#include <g1/tower.h>
#include <unordered_map>

namespace g3 {
	struct theme;

	enum class frame_type {
		SUBSCRIBE = 0,
		PUBLISH = 1,
		MESSAGE = 2,
	};

	struct subheader {
		frame_type type;

		uint8_t thm_size;

		union {
			//PUBLISH
			struct {
				uint16_t dat_size;
			};

			//SUBSCRIBE
			struct {
				g1::QoS qos;
				uint16_t ackquant;
			};
		};
	};

	struct subscribe {
		theme* 		tptr;

		union {
			struct { ///< g3 
				g1::QoS qos;
			};

			struct { ///< g2 socket
								
			};
		};
	};

	struct subscriber {
		std::unordered_map<std::string, subscribe> themes;	

		uint8_t* 	raddr_ptr;
		size_t 		raddr_len;
	
		uint8_t 	proto;

		
	};

	struct theme {
		std::unordered_map<std::string, subscriber*> subscribers;
	};

	void incoming(g1::packet* pack);
	void incoming_dataframe(const char* data, size_t size);


}

#endif