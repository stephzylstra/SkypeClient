#include "skype-embedded_2.h"
#include "sidg_msgs_skylib.hpp"
#ifdef SE_USE_NAMESPACE
namespace skylib {
#endif
        Sid::Protocol::Status Skype::dispatch_event(Sid::CommandInitiator* thread, Sid::Protocol::ClientInterface* protocol, const uint& modid, const uint& evid) {
                switch (modid) {
                        case 0:
                                switch(evid) {
                                        case 1: { //Skype::OnNewCustomContactGroup
                                                MsgcontactOnNewCustomContactGroup msg;
                                                if (protocol->rd_parms(thread,&skylibFields[0],MsgcontactOnNewCustomContactGroup::BEGIN,&msg) != Sid::Protocol::OK) return Sid::Protocol::ERR_DECODE;
                                                OnNewCustomContactGroup(msg.group);
                                                return Sid::Protocol::OK;
                                        }
                                        case 2: { //Skype::OnContactOnlineAppearance
                                                MsgcontactOnContactOnlineAppearance msg;
                                                if (protocol->rd_parms(thread,&skylibFields[0],MsgcontactOnContactOnlineAppearance::BEGIN,&msg) != Sid::Protocol::OK) return Sid::Protocol::ERR_DECODE;
                                                OnContactOnlineAppearance(msg.contact);
                                                return Sid::Protocol::OK;
                                        }
                                        case 3: { //Skype::OnContactGoneOffline
                                                MsgcontactOnContactGoneOffline msg;
                                                if (protocol->rd_parms(thread,&skylibFields[0],MsgcontactOnContactGoneOffline::BEGIN,&msg) != Sid::Protocol::OK) return Sid::Protocol::ERR_DECODE;
                                                OnContactGoneOffline(msg.contact);
                                                return Sid::Protocol::OK;
                                        }
                                        case 4: { //Skype::OnConversationListChange
                                                MsgconversationOnConversationListChange msg;
                                                if (protocol->rd_parms(thread,&skylibFields[0],MsgconversationOnConversationListChange::BEGIN,&msg) != Sid::Protocol::OK) return Sid::Protocol::ERR_DECODE;
                                                OnConversationListChange(msg.conversation,static_cast<Conversation::LIST_TYPE>(msg.type),msg.added);
                                                return Sid::Protocol::OK;
                                        }
                                        case 5: { //Skype::OnMessage
                                                MsgconversationOnMessage msg;
                                                if (protocol->rd_parms(thread,&skylibFields[0],MsgconversationOnMessage::BEGIN,&msg) != Sid::Protocol::OK) return Sid::Protocol::ERR_DECODE;
                                                OnMessage(msg.message,msg.changesInboxTimestamp,msg.supersedesHistoryMessage,msg.conversation);
                                                Conversation* o = static_cast<Conversation*>(__can_dispatch(&msg.conversation));
                                                if (o) o->OnMessage(msg.message);
                                                return Sid::Protocol::OK;
                                        }
                                        case 7: { //Skype::OnAvailableVideoDeviceListChange
                                                if (protocol->rd_parms(thread) != Sid::Protocol::OK) return Sid::Protocol::ERR_DECODE;
                                                OnAvailableVideoDeviceListChange();
                                                return Sid::Protocol::OK;
                                        }
                                        case 10: { //Skype::OnAvailableDeviceListChange
                                                if (protocol->rd_parms(thread) != Sid::Protocol::OK) return Sid::Protocol::ERR_DECODE;
                                                OnAvailableDeviceListChange();
                                                return Sid::Protocol::OK;
                                        }
                                        case 11: { //Skype::OnNrgLevelsChange
                                                if (protocol->rd_parms(thread) != Sid::Protocol::OK) return Sid::Protocol::ERR_DECODE;
                                                OnNrgLevelsChange();
                                                return Sid::Protocol::OK;
                                        }
                                        case 12: { //Skype::OnProxyAuthFailure
                                                MsgconnectionOnProxyAuthFailure msg;
                                                if (protocol->rd_parms(thread,&skylibFields[0],MsgconnectionOnProxyAuthFailure::BEGIN,&msg) != Sid::Protocol::OK) return Sid::Protocol::ERR_DECODE;
                                                OnProxyAuthFailure(static_cast<Skype::PROXYTYPE>(msg.type));
                                                return Sid::Protocol::OK;
                                        }
                                        case 6: { //Skype::OnApp2AppDatagram
                                                Msgapp2appOnApp2AppDatagram msg;
                                                if (protocol->rd_parms(thread,&skylibFields[0],Msgapp2appOnApp2AppDatagram::BEGIN,&msg) != Sid::Protocol::OK) return Sid::Protocol::ERR_DECODE;
                                                OnApp2AppDatagram(msg.appname,msg.stream,msg.data);
                                                return Sid::Protocol::OK;
                                        }
                                        case 8: { //Skype::OnApp2AppStreamListChange
                                                Msgapp2appOnApp2AppStreamListChange msg;
                                                if (protocol->rd_parms(thread,&skylibFields[0],Msgapp2appOnApp2AppStreamListChange::BEGIN,&msg) != Sid::Protocol::OK) return Sid::Protocol::ERR_DECODE;
                                                OnApp2AppStreamListChange(msg.appname,static_cast<Skype::APP2APP_STREAMS>(msg.listType),msg.streams,msg.receivedSizes);
                                                return Sid::Protocol::OK;
                                        }
                                        default: return protocol->sk_parms(thread);
                                }
                        case 10: // ContactGroup
                                switch(evid) {
                                        case 1: { //ContactGroup::OnChangeConversation
                                                MsgcontactContactGroupOnChangeConversation msg;
                                                if (protocol->rd_parms(thread,&skylibFields[0],MsgcontactContactGroupOnChangeConversation::BEGIN,&msg) != Sid::Protocol::OK) return Sid::Protocol::ERR_DECODE;
                                                ContactGroup* o = static_cast<ContactGroup*>(__can_dispatch(&msg.objectID));
                                                if (o) o->OnChangeConversation(msg.conversation);
                                                return Sid::Protocol::OK;
                                        }
                                        case 2: { //ContactGroup::OnChange
                                                MsgcontactContactGroupOnChange msg;
                                                if (protocol->rd_parms(thread,&skylibFields[0],MsgcontactContactGroupOnChange::BEGIN,&msg) != Sid::Protocol::OK) return Sid::Protocol::ERR_DECODE;
                                                ContactGroup* o = static_cast<ContactGroup*>(__can_dispatch(&msg.objectID));
                                                if (o) o->OnChange(msg.contact);
                                                return Sid::Protocol::OK;
                                        }
                                        default: return protocol->sk_parms(thread);
                                }
                        case 1: // ContactSearch
                                switch(evid) {
                                        case 1: { //ContactSearch::OnNewResult
                                                MsgcontactsearchContactSearchOnNewResult msg;
                                                if (protocol->rd_parms(thread,&skylibFields[0],MsgcontactsearchContactSearchOnNewResult::BEGIN,&msg) != Sid::Protocol::OK) return Sid::Protocol::ERR_DECODE;
                                                ContactSearch* o = static_cast<ContactSearch*>(__can_dispatch(&msg.objectID));
                                                if (o) o->OnNewResult(msg.contact,msg.rankValue);
                                                return Sid::Protocol::OK;
                                        }
                                        default: return protocol->sk_parms(thread);
                                }
                        case 19: // Participant
                                switch(evid) {
                                        case 1: { //Participant::OnIncomingDTMF
                                                MsgconversationParticipantOnIncomingDTMF msg;
                                                if (protocol->rd_parms(thread,&skylibFields[0],MsgconversationParticipantOnIncomingDTMF::BEGIN,&msg) != Sid::Protocol::OK) return Sid::Protocol::ERR_DECODE;
                                                Participant* o = static_cast<Participant*>(__can_dispatch(&msg.objectID));
                                                if (o) o->OnIncomingDTMF(static_cast<Participant::DTMF>(msg.dtmf));
                                                return Sid::Protocol::OK;
                                        }
                                        default: return protocol->sk_parms(thread);
                                }
                        case 18: // Conversation
                                switch(evid) {
                                        case 1: { //Conversation::OnParticipantListChange
                                                MsgconversationConversationOnParticipantListChange msg;
                                                if (protocol->rd_parms(thread,&skylibFields[0],MsgconversationConversationOnParticipantListChange::BEGIN,&msg) != Sid::Protocol::OK) return Sid::Protocol::ERR_DECODE;
                                                Conversation* o = static_cast<Conversation*>(__can_dispatch(&msg.objectID));
                                                if (o) o->OnParticipantListChange();
                                                return Sid::Protocol::OK;
                                        }
                                        case 2: { //Conversation::OnMessage
                                                MsgconversationConversationOnMessage msg;
                                                if (protocol->rd_parms(thread,&skylibFields[0],MsgconversationConversationOnMessage::BEGIN,&msg) != Sid::Protocol::OK) return Sid::Protocol::ERR_DECODE;
                                                Conversation* o = static_cast<Conversation*>(__can_dispatch(&msg.objectID));
                                                if (o) o->OnMessage(msg.message);
                                                return Sid::Protocol::OK;
                                        }
                                        case 3: { //Conversation::OnSpawnConference
                                                MsgconversationConversationOnSpawnConference msg;
                                                if (protocol->rd_parms(thread,&skylibFields[0],MsgconversationConversationOnSpawnConference::BEGIN,&msg) != Sid::Protocol::OK) return Sid::Protocol::ERR_DECODE;
                                                Conversation* o = static_cast<Conversation*>(__can_dispatch(&msg.objectID));
                                                if (o) o->OnSpawnConference(msg.spawned);
                                                return Sid::Protocol::OK;
                                        }
                                        default: return protocol->sk_parms(thread);
                                }
                        case 11: // Video
                                switch(evid) {
                                        case 2: { //Video::OnCaptureRequestCompleted
                                                MsgvideoVideoOnCaptureRequestCompleted msg;
                                                if (protocol->rd_parms(thread,&skylibFields[0],MsgvideoVideoOnCaptureRequestCompleted::BEGIN,&msg) != Sid::Protocol::OK) return Sid::Protocol::ERR_DECODE;
                                                Video* o = static_cast<Video*>(__can_dispatch(&msg.objectID));
                                                if (o) o->OnCaptureRequestCompleted(msg.requestId,msg.isSuccessful,msg.image,msg.width,msg.height);
                                                return Sid::Protocol::OK;
                                        }
                                        case 1: { //Video::OnLastFrameCapture
                                                MsgvideoVideoOnLastFrameCapture msg;
                                                if (protocol->rd_parms(thread,&skylibFields[0],MsgvideoVideoOnLastFrameCapture::BEGIN,&msg) != Sid::Protocol::OK) return Sid::Protocol::ERR_DECODE;
                                                Video* o = static_cast<Video*>(__can_dispatch(&msg.objectID));
                                                if (o) o->OnLastFrameCapture(msg.image,msg.width,msg.height);
                                                return Sid::Protocol::OK;
                                        }
                                        default: return protocol->sk_parms(thread);
                                }
                        default: return protocol->sk_parms(thread);
                }
                }
        #ifdef SE_USE_NAMESPACE
        } // skylib
        #endif
