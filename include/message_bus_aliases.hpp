#ifndef __GUARD_MESSAGE_BUS_ALIASES_HPP__
#define __GUARD_MESSAGE_BUS_ALIASES_HPP__

#include <threaded_system.hpp>
#include <message_bus.hpp>
#include <message.hpp>
#include <detail/messaging_policies.hpp>

typedef BasicMessageBus<Message, detail::messaging_policies::basic> MessageBus;
typedef BasicMessageBus<Message, detail::messaging_policies::alias<>> AliasMessageBus;
typedef ThreadedSystem<Message, AliasMessageBus> StandardSystem; 

#endif
