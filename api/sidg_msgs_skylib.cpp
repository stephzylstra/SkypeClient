#include "SidPlatform.hpp"
#include "SidField.hpp"
#include "skype-embedded_2.h"
#include "sidg_msgs_skylib.hpp"

#ifdef SE_USE_NAMESPACE
namespace skylib {
#endif
        static const Sid::String d1="";
        static bool d1field_equals_default(const void* p) { return d1 == *reinterpret_cast<const Sid::String*>(p);}
        static void d1set_field_to_default(void* p) { *reinterpret_cast<Sid::String*>(p) = d1;}
        static const ContactGroupRef d2=0;
        static bool d2field_equals_default(const void* p) { return d2 == *reinterpret_cast<const ContactGroupRef*>(p);}
        static void d2set_field_to_default(void* p) { *reinterpret_cast<ContactGroupRef*>(p) = d2;}
        static const bool d3=false;
        static bool d3field_equals_default(const void* p) { return d3 == *reinterpret_cast<const bool*>(p);}
        static void d3set_field_to_default(void* p) { *reinterpret_cast<bool*>(p) = d3;}
        static bool d4field_equals_default(const void* p) { return reinterpret_cast<const ConversationRefs*>(p)->size()==0; }
        static void d4set_field_to_default(void* p) { reinterpret_cast<ConversationRefs*>(p)->clear(); }
        static void d4append(void* list, uint size, void*& elem) {
                ConversationRefs* l=reinterpret_cast<ConversationRefs*>(list);
                l->append(ConversationRef());
                elem = (void*) &(((const ConversationRefs*)l)->operator[](size));
        };
        static void* d4iterate(void* list, uint count) {
                ConversationRefs* l=reinterpret_cast<ConversationRefs*>(list);
                if (count >= (uint)l->size()) return 0;
                return (void*) &(((const ConversationRefs*)l)->operator[](count));
        };
        static const ConversationRef d5=0;
        static bool d5field_equals_default(const void* p) { return d5 == *reinterpret_cast<const ConversationRef*>(p);}
        static void d5set_field_to_default(void* p) { *reinterpret_cast<ConversationRef*>(p) = d5;}
        static bool d6field_equals_default(const void* p) { return reinterpret_cast<const ContactRefs*>(p)->size()==0; }
        static void d6set_field_to_default(void* p) { reinterpret_cast<ContactRefs*>(p)->clear(); }
        static void d6append(void* list, uint size, void*& elem) {
                ContactRefs* l=reinterpret_cast<ContactRefs*>(list);
                l->append(ContactRef());
                elem = (void*) &(((const ContactRefs*)l)->operator[](size));
        };
        static void* d6iterate(void* list, uint count) {
                ContactRefs* l=reinterpret_cast<ContactRefs*>(list);
                if (count >= (uint)l->size()) return 0;
                return (void*) &(((const ContactRefs*)l)->operator[](count));
        };
        static const ContactRef d7=0;
        static bool d7field_equals_default(const void* p) { return d7 == *reinterpret_cast<const ContactRef*>(p);}
        static void d7set_field_to_default(void* p) { *reinterpret_cast<ContactRef*>(p) = d7;}
        static const uint d8=0;
        static bool d8field_equals_default(const void* p) { return d8 == *reinterpret_cast<const uint*>(p);}
        static void d8set_field_to_default(void* p) { *reinterpret_cast<uint*>(p) = d8;}
        static const int d9=0;
        static bool d9field_equals_default(const void* p) { return d9 == *reinterpret_cast<const int*>(p);}
        static void d9set_field_to_default(void* p) { *reinterpret_cast<int*>(p) = d9;}
        static bool d10field_equals_default(const void* p) { return reinterpret_cast<const ContactGroupRefs*>(p)->size()==0; }
        static void d10set_field_to_default(void* p) { reinterpret_cast<ContactGroupRefs*>(p)->clear(); }
        static void d10append(void* list, uint size, void*& elem) {
                ContactGroupRefs* l=reinterpret_cast<ContactGroupRefs*>(list);
                l->append(ContactGroupRef());
                elem = (void*) &(((const ContactGroupRefs*)l)->operator[](size));
        };
        static void* d10iterate(void* list, uint count) {
                ContactGroupRefs* l=reinterpret_cast<ContactGroupRefs*>(list);
                if (count >= (uint)l->size()) return 0;
                return (void*) &(((const ContactGroupRefs*)l)->operator[](count));
        };
        static const Sid::Binary d11=Sid::Binary();
        static bool d11field_equals_default(const void* p) { return d11 == *reinterpret_cast<const Sid::Binary*>(p);}
        static void d11set_field_to_default(void* p) { *reinterpret_cast<Sid::Binary*>(p) = d11;}
        static const bool d12=0;
        static bool d12field_equals_default(const void* p) { return d12 == *reinterpret_cast<const bool*>(p);}
        static void d12set_field_to_default(void* p) { *reinterpret_cast<bool*>(p) = d12;}
        static const bool d13=1;
        static bool d13field_equals_default(const void* p) { return d13 == *reinterpret_cast<const bool*>(p);}
        static void d13set_field_to_default(void* p) { *reinterpret_cast<bool*>(p) = d13;}
        static const ContactSearchRef d14=0;
        static bool d14field_equals_default(const void* p) { return d14 == *reinterpret_cast<const ContactSearchRef*>(p);}
        static void d14set_field_to_default(void* p) { *reinterpret_cast<ContactSearchRef*>(p) = d14;}
        static const uint d15=MAX_UINT;
        static bool d15field_equals_default(const void* p) { return d15 == *reinterpret_cast<const uint*>(p);}
        static void d15set_field_to_default(void* p) { *reinterpret_cast<uint*>(p) = d15;}
        static bool d16field_equals_default(const void* p) { return reinterpret_cast<const Sid::List_uint*>(p)->size()==0; }
        static void d16set_field_to_default(void* p) { reinterpret_cast<Sid::List_uint*>(p)->clear(); }
        static void d16append(void* list, uint size, void*& elem) {
                Sid::List_uint* l=reinterpret_cast<Sid::List_uint*>(list);
                l->append(uint());
                elem = (void*) &(((const Sid::List_uint*)l)->operator[](size));
        };
        static void* d16iterate(void* list, uint count) {
                Sid::List_uint* l=reinterpret_cast<Sid::List_uint*>(list);
                if (count >= (uint)l->size()) return 0;
                return (void*) &(((const Sid::List_uint*)l)->operator[](count));
        };
        static const ParticipantRef d17=0;
        static bool d17field_equals_default(const void* p) { return d17 == *reinterpret_cast<const ParticipantRef*>(p);}
        static void d17set_field_to_default(void* p) { *reinterpret_cast<ParticipantRef*>(p) = d17;}
        static const VideoRef d18=0;
        static bool d18field_equals_default(const void* p) { return d18 == *reinterpret_cast<const VideoRef*>(p);}
        static void d18set_field_to_default(void* p) { *reinterpret_cast<VideoRef*>(p) = d18;}
        static bool d19field_equals_default(const void* p) { return reinterpret_cast<const Sid::List_String*>(p)->size()==0; }
        static void d19set_field_to_default(void* p) { reinterpret_cast<Sid::List_String*>(p)->clear(); }
        static void d19append(void* list, uint size, void*& elem) {
                Sid::List_String* l=reinterpret_cast<Sid::List_String*>(list);
                l->append(Sid::String());
                elem = (void*) &(((const Sid::List_String*)l)->operator[](size));
        };
        static void* d19iterate(void* list, uint count) {
                Sid::List_String* l=reinterpret_cast<Sid::List_String*>(list);
                if (count >= (uint)l->size()) return 0;
                return (void*) &(((const Sid::List_String*)l)->operator[](count));
        };
        static const uint d20=260;
        static bool d20field_equals_default(const void* p) { return d20 == *reinterpret_cast<const uint*>(p);}
        static void d20set_field_to_default(void* p) { *reinterpret_cast<uint*>(p) = d20;}
        static const MessageRef d21=0;
        static bool d21field_equals_default(const void* p) { return d21 == *reinterpret_cast<const MessageRef*>(p);}
        static void d21set_field_to_default(void* p) { *reinterpret_cast<MessageRef*>(p) = d21;}
        static bool d22field_equals_default(const void* p) { return reinterpret_cast<const Sid::List_Filename*>(p)->size()==0; }
        static void d22set_field_to_default(void* p) { reinterpret_cast<Sid::List_Filename*>(p)->clear(); }
        static void d22append(void* list, uint size, void*& elem) {
                Sid::List_Filename* l=reinterpret_cast<Sid::List_Filename*>(list);
                l->append(Sid::Filename());
                elem = (void*) &(((const Sid::List_Filename*)l)->operator[](size));
        };
        static void* d22iterate(void* list, uint count) {
                Sid::List_Filename* l=reinterpret_cast<Sid::List_Filename*>(list);
                if (count >= (uint)l->size()) return 0;
                return (void*) &(((const Sid::List_Filename*)l)->operator[](count));
        };
        static const Sid::Filename d23="";
        static bool d23field_equals_default(const void* p) { return d23 == *reinterpret_cast<const Sid::Filename*>(p);}
        static void d23set_field_to_default(void* p) { *reinterpret_cast<Sid::Filename*>(p) = d23;}
        static const VoicemailRef d24=0;
        static bool d24field_equals_default(const void* p) { return d24 == *reinterpret_cast<const VoicemailRef*>(p);}
        static void d24set_field_to_default(void* p) { *reinterpret_cast<VoicemailRef*>(p) = d24;}
        static const SmsRef d25=0;
        static bool d25field_equals_default(const void* p) { return d25 == *reinterpret_cast<const SmsRef*>(p);}
        static void d25set_field_to_default(void* p) { *reinterpret_cast<SmsRef*>(p) = d25;}
        static bool d26field_equals_default(const void* p) { return reinterpret_cast<const ParticipantRefs*>(p)->size()==0; }
        static void d26set_field_to_default(void* p) { reinterpret_cast<ParticipantRefs*>(p)->clear(); }
        static void d26append(void* list, uint size, void*& elem) {
                ParticipantRefs* l=reinterpret_cast<ParticipantRefs*>(list);
                l->append(ParticipantRef());
                elem = (void*) &(((const ParticipantRefs*)l)->operator[](size));
        };
        static void* d26iterate(void* list, uint count) {
                ParticipantRefs* l=reinterpret_cast<ParticipantRefs*>(list);
                if (count >= (uint)l->size()) return 0;
                return (void*) &(((const ParticipantRefs*)l)->operator[](count));
        };
        static bool d27field_equals_default(const void* p) { return reinterpret_cast<const MessageRefs*>(p)->size()==0; }
        static void d27set_field_to_default(void* p) { reinterpret_cast<MessageRefs*>(p)->clear(); }
        static void d27append(void* list, uint size, void*& elem) {
                MessageRefs* l=reinterpret_cast<MessageRefs*>(list);
                l->append(MessageRef());
                elem = (void*) &(((const MessageRefs*)l)->operator[](size));
        };
        static void* d27iterate(void* list, uint count) {
                MessageRefs* l=reinterpret_cast<MessageRefs*>(list);
                if (count >= (uint)l->size()) return 0;
                return (void*) &(((const MessageRefs*)l)->operator[](count));
        };
        static bool d28field_equals_default(const void* p) { return reinterpret_cast<const TransferRefs*>(p)->size()==0; }
        static void d28set_field_to_default(void* p) { reinterpret_cast<TransferRefs*>(p)->clear(); }
        static void d28append(void* list, uint size, void*& elem) {
                TransferRefs* l=reinterpret_cast<TransferRefs*>(list);
                l->append(TransferRef());
                elem = (void*) &(((const TransferRefs*)l)->operator[](size));
        };
        static void* d28iterate(void* list, uint count) {
                TransferRefs* l=reinterpret_cast<TransferRefs*>(list);
                if (count >= (uint)l->size()) return 0;
                return (void*) &(((const TransferRefs*)l)->operator[](count));
        };
        static const TransferRef d29=0;
        static bool d29field_equals_default(const void* p) { return d29 == *reinterpret_cast<const TransferRef*>(p);}
        static void d29set_field_to_default(void* p) { *reinterpret_cast<TransferRef*>(p) = d29;}
        static const AccountRef d30=0;
        static bool d30field_equals_default(const void* p) { return d30 == *reinterpret_cast<const AccountRef*>(p);}
        static void d30set_field_to_default(void* p) { *reinterpret_cast<AccountRef*>(p) = d30;}
        static char* base_address=0;
        Sid::Field skylibFields[] = {
                /*** MsgconfigGetVersionStringResponse */
                /*0*/ { { {&d1field_equals_default,&d1set_field_to_default,1,Sid::Field::FLD_FIRST,Sid::Field::KIND_STRING, MsgconfigGetVersionStringResponse::END,0} } },
                /*** MsgcontactContactGroupGiveDisplayNameRequest */
                /*1*/ { { {&d2field_equals_default,&d2set_field_to_default,0,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgcontactContactGroupGiveDisplayNameRequest::END,10} } },
                /*2*/ { { {&d1field_equals_default,&d1set_field_to_default,1,0,Sid::Field::KIND_STRING, (unsigned short) (size_t) &reinterpret_cast<MsgcontactContactGroupGiveDisplayNameRequest*>(base_address)->name,0} } },
                /*** MsgcontactContactGroupDeleteRequest */
                /*3*/ { { {&d2field_equals_default,&d2set_field_to_default,0,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgcontactContactGroupDeleteRequest::END,10} } },
                /*** MsgcontactContactGroupDeleteResponse */
                /*4*/ { { {&d3field_equals_default,&d3set_field_to_default,1,Sid::Field::FLD_FIRST,Sid::Field::KIND_BOOLEAN, MsgcontactContactGroupDeleteResponse::END,0} } },
                /*** MsgcontactContactGroupGetConversationsRequest */
                /*5*/ { { {&d2field_equals_default,&d2set_field_to_default,0,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgcontactContactGroupGetConversationsRequest::END,10} } },
                /*** MsgcontactContactGroupGetConversationsResponse */
                /*6*/ { { {&d4field_equals_default,&d4set_field_to_default,1,Sid::Field::FLD_FIRST|Sid::Field::FLD_LIST,Sid::Field::KIND_OBJECTID, MsgcontactContactGroupGetConversationsResponse::END,18} } },
                { { { reinterpret_cast<bool(*)(const void*)>(&d4append),reinterpret_cast<void(*)(void*)>(&d4iterate),0,0,0,0,0}}},
                /*** MsgcontactContactGroupCanAddConversationRequest */
                /*8*/ { { {&d2field_equals_default,&d2set_field_to_default,0,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgcontactContactGroupCanAddConversationRequest::END,10} } },
                /*9*/ { { {&d5field_equals_default,&d5set_field_to_default,1,0,Sid::Field::KIND_OBJECTID, (unsigned short) (size_t) &reinterpret_cast<MsgcontactContactGroupCanAddConversationRequest*>(base_address)->conversation,18} } },
                /*** MsgcontactContactGroupCanAddConversationResponse */
                /*10*/ { { {&d3field_equals_default,&d3set_field_to_default,1,Sid::Field::FLD_FIRST,Sid::Field::KIND_BOOLEAN, MsgcontactContactGroupCanAddConversationResponse::END,0} } },
                /*** MsgcontactContactGroupAddConversationRequest */
                /*11*/ { { {&d2field_equals_default,&d2set_field_to_default,0,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgcontactContactGroupAddConversationRequest::END,10} } },
                /*12*/ { { {&d5field_equals_default,&d5set_field_to_default,1,0,Sid::Field::KIND_OBJECTID, (unsigned short) (size_t) &reinterpret_cast<MsgcontactContactGroupAddConversationRequest*>(base_address)->conversation,18} } },
                /*** MsgcontactContactGroupCanRemoveConversationRequest */
                /*13*/ { { {&d2field_equals_default,&d2set_field_to_default,0,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgcontactContactGroupCanRemoveConversationRequest::END,10} } },
                /*** MsgcontactContactGroupCanRemoveConversationResponse */
                /*14*/ { { {&d3field_equals_default,&d3set_field_to_default,1,Sid::Field::FLD_FIRST,Sid::Field::KIND_BOOLEAN, MsgcontactContactGroupCanRemoveConversationResponse::END,0} } },
                /*** MsgcontactContactGroupRemoveConversationRequest */
                /*15*/ { { {&d2field_equals_default,&d2set_field_to_default,0,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgcontactContactGroupRemoveConversationRequest::END,10} } },
                /*16*/ { { {&d5field_equals_default,&d5set_field_to_default,1,0,Sid::Field::KIND_OBJECTID, (unsigned short) (size_t) &reinterpret_cast<MsgcontactContactGroupRemoveConversationRequest*>(base_address)->conversation,18} } },
                /*** MsgcontactContactGroupOnChangeConversation */
                /*17*/ { { {&d2field_equals_default,&d2set_field_to_default,0,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgcontactContactGroupOnChangeConversation::END,10} } },
                /*18*/ { { {&d5field_equals_default,&d5set_field_to_default,1,0,Sid::Field::KIND_OBJECTID, (unsigned short) (size_t) &reinterpret_cast<MsgcontactContactGroupOnChangeConversation*>(base_address)->conversation,18} } },
                /*** MsgcontactContactGroupGetContactsRequest */
                /*19*/ { { {&d2field_equals_default,&d2set_field_to_default,0,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgcontactContactGroupGetContactsRequest::END,10} } },
                /*** MsgcontactContactGroupGetContactsResponse */
                /*20*/ { { {&d6field_equals_default,&d6set_field_to_default,1,Sid::Field::FLD_FIRST|Sid::Field::FLD_LIST,Sid::Field::KIND_OBJECTID, MsgcontactContactGroupGetContactsResponse::END,2} } },
                { { { reinterpret_cast<bool(*)(const void*)>(&d6append),reinterpret_cast<void(*)(void*)>(&d6iterate),0,0,0,0,0}}},
                /*** MsgcontactContactGroupCanAddContactRequest */
                /*22*/ { { {&d2field_equals_default,&d2set_field_to_default,0,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgcontactContactGroupCanAddContactRequest::END,10} } },
                /*23*/ { { {&d7field_equals_default,&d7set_field_to_default,1,0,Sid::Field::KIND_OBJECTID, (unsigned short) (size_t) &reinterpret_cast<MsgcontactContactGroupCanAddContactRequest*>(base_address)->contact,2} } },
                /*** MsgcontactContactGroupCanAddContactResponse */
                /*24*/ { { {&d3field_equals_default,&d3set_field_to_default,1,Sid::Field::FLD_FIRST,Sid::Field::KIND_BOOLEAN, MsgcontactContactGroupCanAddContactResponse::END,0} } },
                /*** MsgcontactContactGroupAddContactRequest */
                /*25*/ { { {&d2field_equals_default,&d2set_field_to_default,0,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgcontactContactGroupAddContactRequest::END,10} } },
                /*26*/ { { {&d7field_equals_default,&d7set_field_to_default,1,0,Sid::Field::KIND_OBJECTID, (unsigned short) (size_t) &reinterpret_cast<MsgcontactContactGroupAddContactRequest*>(base_address)->contact,2} } },
                /*** MsgcontactContactGroupCanRemoveContactRequest */
                /*27*/ { { {&d2field_equals_default,&d2set_field_to_default,0,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgcontactContactGroupCanRemoveContactRequest::END,10} } },
                /*** MsgcontactContactGroupCanRemoveContactResponse */
                /*28*/ { { {&d3field_equals_default,&d3set_field_to_default,1,Sid::Field::FLD_FIRST,Sid::Field::KIND_BOOLEAN, MsgcontactContactGroupCanRemoveContactResponse::END,0} } },
                /*** MsgcontactContactGroupRemoveContactRequest */
                /*29*/ { { {&d2field_equals_default,&d2set_field_to_default,0,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgcontactContactGroupRemoveContactRequest::END,10} } },
                /*30*/ { { {&d7field_equals_default,&d7set_field_to_default,1,0,Sid::Field::KIND_OBJECTID, (unsigned short) (size_t) &reinterpret_cast<MsgcontactContactGroupRemoveContactRequest*>(base_address)->contact,2} } },
                /*** MsgcontactContactGroupOnChange */
                /*31*/ { { {&d2field_equals_default,&d2set_field_to_default,0,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgcontactContactGroupOnChange::END,10} } },
                /*32*/ { { {&d7field_equals_default,&d7set_field_to_default,1,0,Sid::Field::KIND_OBJECTID, (unsigned short) (size_t) &reinterpret_cast<MsgcontactContactGroupOnChange*>(base_address)->contact,2} } },
                /*** MsgcontactContactGroup */
                /*33*/ { { {&d1field_equals_default,&d1set_field_to_default,151,Sid::Field::FLD_FIRST,Sid::Field::KIND_STRING, MsgcontactContactGroup::END,0} } },
                /*34*/ { { {&d8field_equals_default,&d8set_field_to_default,152,0,Sid::Field::KIND_UINT, (unsigned short) (size_t) &reinterpret_cast<MsgcontactContactGroup*>(base_address)->nrofcontacts,0} } },                /*35*/ { { {&d8field_equals_default,&d8set_field_to_default,153,0,Sid::Field::KIND_UINT, (unsigned short) (size_t) &reinterpret_cast<MsgcontactContactGroup*>(base_address)->nrofcontacts_online,0} } },
                /*36*/ { { {&d8field_equals_default,&d8set_field_to_default,154,0,Sid::Field::KIND_UINT, (unsigned short) (size_t) &reinterpret_cast<MsgcontactContactGroup*>(base_address)->custom_group_id,0} } },
                /*37*/ { { {&d9field_equals_default,&d9set_field_to_default,155,0,Sid::Field::KIND_ENUM, (unsigned short) (size_t) &reinterpret_cast<MsgcontactContactGroup*>(base_address)->type,0} } },
                /*** MsgcontactGetHardwiredContactGroupRequest */
                /*38*/ { { {&d9field_equals_default,&d9set_field_to_default,1,Sid::Field::FLD_FIRST,Sid::Field::KIND_ENUM, MsgcontactGetHardwiredContactGroupRequest::END,0} } },
                /*** MsgcontactGetHardwiredContactGroupResponse */
                /*39*/ { { {&d2field_equals_default,&d2set_field_to_default,1,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgcontactGetHardwiredContactGroupResponse::END,10} } },
                /*** MsgcontactGetCustomContactGroupsResponse */
                /*40*/ { { {&d10field_equals_default,&d10set_field_to_default,1,Sid::Field::FLD_FIRST|Sid::Field::FLD_LIST,Sid::Field::KIND_OBJECTID, MsgcontactGetCustomContactGroupsResponse::END,10} } },
                { { { reinterpret_cast<bool(*)(const void*)>(&d10append),reinterpret_cast<void(*)(void*)>(&d10iterate),0,0,0,0,0}}},
                /*** MsgcontactCreateCustomContactGroupResponse */
                /*42*/ { { {&d2field_equals_default,&d2set_field_to_default,1,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgcontactCreateCustomContactGroupResponse::END,10} } },
                /*** MsgcontactOnNewCustomContactGroup */
                /*43*/ { { {&d2field_equals_default,&d2set_field_to_default,1,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgcontactOnNewCustomContactGroup::END,10} } },
                /*** MsgcontactContactGetTypeRequest */
                /*44*/ { { {&d7field_equals_default,&d7set_field_to_default,0,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgcontactContactGetTypeRequest::END,2} } },
                /*** MsgcontactContactGetTypeResponse */
                /*45*/ { { {&d9field_equals_default,&d9set_field_to_default,1,Sid::Field::FLD_FIRST,Sid::Field::KIND_ENUM, MsgcontactContactGetTypeResponse::END,0} } },
                /*** MsgcontactContactGetIdentityRequest */
                /*46*/ { { {&d7field_equals_default,&d7set_field_to_default,0,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgcontactContactGetIdentityRequest::END,2} } },
                /*** MsgcontactContactGetIdentityResponse */
                /*47*/ { { {&d1field_equals_default,&d1set_field_to_default,1,Sid::Field::FLD_FIRST,Sid::Field::KIND_STRING, MsgcontactContactGetIdentityResponse::END,0} } },
                /*** MsgcontactContactGetAvatarRequest */
                /*48*/ { { {&d7field_equals_default,&d7set_field_to_default,0,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgcontactContactGetAvatarRequest::END,2} } },
                /*** MsgcontactContactGetAvatarResponse */
                /*49*/ { { {&d3field_equals_default,&d3set_field_to_default,1,Sid::Field::FLD_FIRST,Sid::Field::KIND_BOOLEAN, MsgcontactContactGetAvatarResponse::END,0} } },
                /*50*/ { { {&d11field_equals_default,&d11set_field_to_default,2,0,Sid::Field::KIND_BINARY, (unsigned short) (size_t) &reinterpret_cast<MsgcontactContactGetAvatarResponse*>(base_address)->avatar,0} } },
                /*** MsgcontactContactGetVerifiedEmailRequest */
                /*51*/ { { {&d7field_equals_default,&d7set_field_to_default,0,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgcontactContactGetVerifiedEmailRequest::END,2} } },
                /*** MsgcontactContactGetVerifiedEmailResponse */
                /*52*/ { { {&d1field_equals_default,&d1set_field_to_default,1,Sid::Field::FLD_FIRST,Sid::Field::KIND_STRING, MsgcontactContactGetVerifiedEmailResponse::END,0} } },
                /*** MsgcontactContactGetVerifiedCompanyRequest */
                /*53*/ { { {&d7field_equals_default,&d7set_field_to_default,0,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgcontactContactGetVerifiedCompanyRequest::END,2} } },
                /*** MsgcontactContactGetVerifiedCompanyResponse */
                /*54*/ { { {&d1field_equals_default,&d1set_field_to_default,1,Sid::Field::FLD_FIRST,Sid::Field::KIND_STRING, MsgcontactContactGetVerifiedCompanyResponse::END,0} } },
                /*** MsgcontactContactIsMemberOfRequest */
                /*55*/ { { {&d7field_equals_default,&d7set_field_to_default,0,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgcontactContactIsMemberOfRequest::END,2} } },
                /*56*/ { { {&d2field_equals_default,&d2set_field_to_default,1,0,Sid::Field::KIND_OBJECTID, (unsigned short) (size_t) &reinterpret_cast<MsgcontactContactIsMemberOfRequest*>(base_address)->group,10} } },
                /*** MsgcontactContactIsMemberOfResponse */
                /*57*/ { { {&d3field_equals_default,&d3set_field_to_default,1,Sid::Field::FLD_FIRST,Sid::Field::KIND_BOOLEAN, MsgcontactContactIsMemberOfResponse::END,0} } },
                /*** MsgcontactContactIsMemberOfHardwiredGroupRequest */
                /*58*/ { { {&d7field_equals_default,&d7set_field_to_default,0,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgcontactContactIsMemberOfHardwiredGroupRequest::END,2} } },
                /*59*/ { { {&d9field_equals_default,&d9set_field_to_default,1,0,Sid::Field::KIND_ENUM, (unsigned short) (size_t) &reinterpret_cast<MsgcontactContactIsMemberOfHardwiredGroupRequest*>(base_address)->groupType,0} } },
                /*** MsgcontactContactIsMemberOfHardwiredGroupResponse */
                /*60*/ { { {&d3field_equals_default,&d3set_field_to_default,1,Sid::Field::FLD_FIRST,Sid::Field::KIND_BOOLEAN, MsgcontactContactIsMemberOfHardwiredGroupResponse::END,0} } },
                /*** MsgcontactContactSetBlockedRequest */
                /*61*/ { { {&d7field_equals_default,&d7set_field_to_default,0,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgcontactContactSetBlockedRequest::END,2} } },
                /*62*/ { { {&d3field_equals_default,&d3set_field_to_default,1,0,Sid::Field::KIND_BOOLEAN, (unsigned short) (size_t) &reinterpret_cast<MsgcontactContactSetBlockedRequest*>(base_address)->blocked,0} } },
                /*63*/ { { {&d12field_equals_default,&d12set_field_to_default,2,0,Sid::Field::KIND_BOOLEAN, (unsigned short) (size_t) &reinterpret_cast<MsgcontactContactSetBlockedRequest*>(base_address)->abuse,0} } },
                /*** MsgcontactContactIgnoreAuthRequestRequest */
                /*64*/ { { {&d7field_equals_default,&d7set_field_to_default,0,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgcontactContactIgnoreAuthRequestRequest::END,2} } },
                /*** MsgcontactContactGiveDisplayNameRequest */
                /*65*/ { { {&d7field_equals_default,&d7set_field_to_default,0,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgcontactContactGiveDisplayNameRequest::END,2} } },
                /*66*/ { { {&d1field_equals_default,&d1set_field_to_default,1,0,Sid::Field::KIND_STRING, (unsigned short) (size_t) &reinterpret_cast<MsgcontactContactGiveDisplayNameRequest*>(base_address)->name,0} } },
                /*** MsgcontactContactSetBuddyStatusRequest */
                /*67*/ { { {&d7field_equals_default,&d7set_field_to_default,0,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgcontactContactSetBuddyStatusRequest::END,2} } },
                /*68*/ { { {&d3field_equals_default,&d3set_field_to_default,1,0,Sid::Field::KIND_BOOLEAN, (unsigned short) (size_t) &reinterpret_cast<MsgcontactContactSetBuddyStatusRequest*>(base_address)->isMyBuddy,0} } },
                /*69*/ { { {&d13field_equals_default,&d13set_field_to_default,2,0,Sid::Field::KIND_BOOLEAN, (unsigned short) (size_t) &reinterpret_cast<MsgcontactContactSetBuddyStatusRequest*>(base_address)->syncAuth,0} } },
                /*** MsgcontactContactSendAuthRequestRequest */                /*70*/ { { {&d7field_equals_default,&d7set_field_to_default,0,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgcontactContactSendAuthRequestRequest::END,2} } },
                /*71*/ { { {&d1field_equals_default,&d1set_field_to_default,1,0,Sid::Field::KIND_STRING, (unsigned short) (size_t) &reinterpret_cast<MsgcontactContactSendAuthRequestRequest*>(base_address)->message,0} } },
                /*72*/ { { {&d8field_equals_default,&d8set_field_to_default,2,0,Sid::Field::KIND_UINT, (unsigned short) (size_t) &reinterpret_cast<MsgcontactContactSendAuthRequestRequest*>(base_address)->extras_bitmask,0} } },
                /*** MsgcontactContactHasAuthorizedMeRequest */
                /*73*/ { { {&d7field_equals_default,&d7set_field_to_default,0,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgcontactContactHasAuthorizedMeRequest::END,2} } },
                /*** MsgcontactContactHasAuthorizedMeResponse */
                /*74*/ { { {&d3field_equals_default,&d3set_field_to_default,1,Sid::Field::FLD_FIRST,Sid::Field::KIND_BOOLEAN, MsgcontactContactHasAuthorizedMeResponse::END,0} } },
                /*** MsgcontactContactSetPhoneNumberRequest */
                /*75*/ { { {&d7field_equals_default,&d7set_field_to_default,0,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgcontactContactSetPhoneNumberRequest::END,2} } },
                /*76*/ { { {&d8field_equals_default,&d8set_field_to_default,1,0,Sid::Field::KIND_UINT, (unsigned short) (size_t) &reinterpret_cast<MsgcontactContactSetPhoneNumberRequest*>(base_address)->num,0} } },
                /*77*/ { { {&d1field_equals_default,&d1set_field_to_default,2,0,Sid::Field::KIND_STRING, (unsigned short) (size_t) &reinterpret_cast<MsgcontactContactSetPhoneNumberRequest*>(base_address)->label,0} } },
                /*78*/ { { {&d1field_equals_default,&d1set_field_to_default,3,0,Sid::Field::KIND_STRING, (unsigned short) (size_t) &reinterpret_cast<MsgcontactContactSetPhoneNumberRequest*>(base_address)->number,0} } },
                /*** MsgcontactContactOpenConversationRequest */
                /*79*/ { { {&d7field_equals_default,&d7set_field_to_default,0,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgcontactContactOpenConversationRequest::END,2} } },
                /*** MsgcontactContactOpenConversationResponse */
                /*80*/ { { {&d5field_equals_default,&d5set_field_to_default,1,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgcontactContactOpenConversationResponse::END,18} } },
                /*** MsgcontactContactHasCapabilityRequest */
                /*81*/ { { {&d7field_equals_default,&d7set_field_to_default,0,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgcontactContactHasCapabilityRequest::END,2} } },
                /*82*/ { { {&d9field_equals_default,&d9set_field_to_default,1,0,Sid::Field::KIND_ENUM, (unsigned short) (size_t) &reinterpret_cast<MsgcontactContactHasCapabilityRequest*>(base_address)->capability,0} } },
                /*83*/ { { {&d12field_equals_default,&d12set_field_to_default,2,0,Sid::Field::KIND_BOOLEAN, (unsigned short) (size_t) &reinterpret_cast<MsgcontactContactHasCapabilityRequest*>(base_address)->queryServer,0} } },
                /*** MsgcontactContactHasCapabilityResponse */
                /*84*/ { { {&d3field_equals_default,&d3set_field_to_default,1,Sid::Field::FLD_FIRST,Sid::Field::KIND_BOOLEAN, MsgcontactContactHasCapabilityResponse::END,0} } },
                /*** MsgcontactContactGetCapabilityStatusRequest */
                /*85*/ { { {&d7field_equals_default,&d7set_field_to_default,0,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgcontactContactGetCapabilityStatusRequest::END,2} } },
                /*86*/ { { {&d9field_equals_default,&d9set_field_to_default,1,0,Sid::Field::KIND_ENUM, (unsigned short) (size_t) &reinterpret_cast<MsgcontactContactGetCapabilityStatusRequest*>(base_address)->capability,0} } },
                /*87*/ { { {&d12field_equals_default,&d12set_field_to_default,2,0,Sid::Field::KIND_BOOLEAN, (unsigned short) (size_t) &reinterpret_cast<MsgcontactContactGetCapabilityStatusRequest*>(base_address)->queryServer,0} } },
                /*** MsgcontactContactGetCapabilityStatusResponse */
                /*88*/ { { {&d9field_equals_default,&d9set_field_to_default,1,Sid::Field::FLD_FIRST,Sid::Field::KIND_ENUM, MsgcontactContactGetCapabilityStatusResponse::END,0} } },
                /*** MsgcontactContactRefreshProfileRequest */
                /*89*/ { { {&d7field_equals_default,&d7set_field_to_default,0,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgcontactContactRefreshProfileRequest::END,2} } },
                /*** MsgcontactContact */
                /*90*/ { { {&d1field_equals_default,&d1set_field_to_default,4,Sid::Field::FLD_FIRST,Sid::Field::KIND_STRING, MsgcontactContact::END,0} } },
                /*91*/ { { {&d1field_equals_default,&d1set_field_to_default,5,0,Sid::Field::KIND_STRING, (unsigned short) (size_t) &reinterpret_cast<MsgcontactContact*>(base_address)->fullname,0} } },
                /*92*/ { { {&d1field_equals_default,&d1set_field_to_default,6,0,Sid::Field::KIND_STRING, (unsigned short) (size_t) &reinterpret_cast<MsgcontactContact*>(base_address)->pstnnumber,0} } },
                /*93*/ { { {&d8field_equals_default,&d8set_field_to_default,7,0,Sid::Field::KIND_UINT, (unsigned short) (size_t) &reinterpret_cast<MsgcontactContact*>(base_address)->birthday,0} } },
                /*94*/ { { {&d8field_equals_default,&d8set_field_to_default,8,0,Sid::Field::KIND_UINT, (unsigned short) (size_t) &reinterpret_cast<MsgcontactContact*>(base_address)->gender,0} } },
                /*95*/ { { {&d1field_equals_default,&d1set_field_to_default,9,0,Sid::Field::KIND_STRING, (unsigned short) (size_t) &reinterpret_cast<MsgcontactContact*>(base_address)->languages,0} } },
                /*96*/ { { {&d1field_equals_default,&d1set_field_to_default,10,0,Sid::Field::KIND_STRING, (unsigned short) (size_t) &reinterpret_cast<MsgcontactContact*>(base_address)->country,0} } },
                /*97*/ { { {&d1field_equals_default,&d1set_field_to_default,11,0,Sid::Field::KIND_STRING, (unsigned short) (size_t) &reinterpret_cast<MsgcontactContact*>(base_address)->province,0} } },
                /*98*/ { { {&d1field_equals_default,&d1set_field_to_default,12,0,Sid::Field::KIND_STRING, (unsigned short) (size_t) &reinterpret_cast<MsgcontactContact*>(base_address)->city,0} } },
                /*99*/ { { {&d1field_equals_default,&d1set_field_to_default,13,0,Sid::Field::KIND_STRING, (unsigned short) (size_t) &reinterpret_cast<MsgcontactContact*>(base_address)->phone_home,0} } },
                /*100*/ { { {&d1field_equals_default,&d1set_field_to_default,14,0,Sid::Field::KIND_STRING, (unsigned short) (size_t) &reinterpret_cast<MsgcontactContact*>(base_address)->phone_office,0} } },
                /*101*/ { { {&d1field_equals_default,&d1set_field_to_default,15,0,Sid::Field::KIND_STRING, (unsigned short) (size_t) &reinterpret_cast<MsgcontactContact*>(base_address)->phone_mobile,0} } },
                /*102*/ { { {&d1field_equals_default,&d1set_field_to_default,16,0,Sid::Field::KIND_STRING, (unsigned short) (size_t) &reinterpret_cast<MsgcontactContact*>(base_address)->emails,0} } },
                /*103*/ { { {&d1field_equals_default,&d1set_field_to_default,17,0,Sid::Field::KIND_STRING, (unsigned short) (size_t) &reinterpret_cast<MsgcontactContact*>(base_address)->homepage,0} } },
                /*104*/ { { {&d1field_equals_default,&d1set_field_to_default,18,0,Sid::Field::KIND_STRING, (unsigned short) (size_t) &reinterpret_cast<MsgcontactContact*>(base_address)->about,0} } },
                /*105*/ { { {&d8field_equals_default,&d8set_field_to_default,19,0,Sid::Field::KIND_UINT, (unsigned short) (size_t) &reinterpret_cast<MsgcontactContact*>(base_address)->profile_timestamp,0} } },
                /*106*/ { { {&d1field_equals_default,&d1set_field_to_default,20,0,Sid::Field::KIND_STRING, (unsigned short) (size_t) &reinterpret_cast<MsgcontactContact*>(base_address)->received_authrequest,0} } },
                /*107*/ { { {&d1field_equals_default,&d1set_field_to_default,21,0,Sid::Field::KIND_STRING, (unsigned short) (size_t) &reinterpret_cast<MsgcontactContact*>(base_address)->displayname,0} } },                /*108*/ { { {&d3field_equals_default,&d3set_field_to_default,22,0,Sid::Field::KIND_BOOLEAN, (unsigned short) (size_t) &reinterpret_cast<MsgcontactContact*>(base_address)->refreshing,0} } },
                /*109*/ { { {&d9field_equals_default,&d9set_field_to_default,23,0,Sid::Field::KIND_ENUM, (unsigned short) (size_t) &reinterpret_cast<MsgcontactContact*>(base_address)->given_authlevel,0} } },
                /*110*/ { { {&d8field_equals_default,&d8set_field_to_default,25,0,Sid::Field::KIND_UINT, (unsigned short) (size_t) &reinterpret_cast<MsgcontactContact*>(base_address)->authreq_timestamp,0} } },
                /*111*/ { { {&d1field_equals_default,&d1set_field_to_default,26,0,Sid::Field::KIND_STRING, (unsigned short) (size_t) &reinterpret_cast<MsgcontactContact*>(base_address)->mood_text,0} } },
                /*112*/ { { {&d8field_equals_default,&d8set_field_to_default,27,0,Sid::Field::KIND_UINT, (unsigned short) (size_t) &reinterpret_cast<MsgcontactContact*>(base_address)->timezone,0} } },
                /*113*/ { { {&d8field_equals_default,&d8set_field_to_default,28,0,Sid::Field::KIND_UINT, (unsigned short) (size_t) &reinterpret_cast<MsgcontactContact*>(base_address)->nrof_authed_buddies,0} } },
                /*114*/ { { {&d1field_equals_default,&d1set_field_to_default,29,0,Sid::Field::KIND_STRING, (unsigned short) (size_t) &reinterpret_cast<MsgcontactContact*>(base_address)->ipcountry,0} } },
                /*115*/ { { {&d1field_equals_default,&d1set_field_to_default,33,0,Sid::Field::KIND_STRING, (unsigned short) (size_t) &reinterpret_cast<MsgcontactContact*>(base_address)->given_displayname,0} } },
                /*116*/ { { {&d9field_equals_default,&d9set_field_to_default,34,0,Sid::Field::KIND_ENUM, (unsigned short) (size_t) &reinterpret_cast<MsgcontactContact*>(base_address)->availability,0} } },
                /*117*/ { { {&d8field_equals_default,&d8set_field_to_default,35,0,Sid::Field::KIND_UINT, (unsigned short) (size_t) &reinterpret_cast<MsgcontactContact*>(base_address)->lastonline_timestamp,0} } },
                /*118*/ { { {&d11field_equals_default,&d11set_field_to_default,36,0,Sid::Field::KIND_BINARY, (unsigned short) (size_t) &reinterpret_cast<MsgcontactContact*>(base_address)->capabilities,0} } },
                /*119*/ { { {&d11field_equals_default,&d11set_field_to_default,37,0,Sid::Field::KIND_BINARY, (unsigned short) (size_t) &reinterpret_cast<MsgcontactContact*>(base_address)->avatar_image,0} } },
                /*120*/ { { {&d8field_equals_default,&d8set_field_to_default,39,0,Sid::Field::KIND_UINT, (unsigned short) (size_t) &reinterpret_cast<MsgcontactContact*>(base_address)->lastused_timestamp,0} } },
                /*121*/ { { {&d8field_equals_default,&d8set_field_to_default,41,0,Sid::Field::KIND_UINT, (unsigned short) (size_t) &reinterpret_cast<MsgcontactContact*>(base_address)->authrequest_count,0} } },
                /*122*/ { { {&d8field_equals_default,&d8set_field_to_default,42,0,Sid::Field::KIND_UINT, (unsigned short) (size_t) &reinterpret_cast<MsgcontactContact*>(base_address)->popularity_ord,0} } },
                /*123*/ { { {&d1field_equals_default,&d1set_field_to_default,180,0,Sid::Field::KIND_STRING, (unsigned short) (size_t) &reinterpret_cast<MsgcontactContact*>(base_address)->assigned_comment,0} } },
                /*124*/ { { {&d8field_equals_default,&d8set_field_to_default,182,0,Sid::Field::KIND_UINT, (unsigned short) (size_t) &reinterpret_cast<MsgcontactContact*>(base_address)->avatar_timestamp,0} } },
                /*125*/ { { {&d8field_equals_default,&d8set_field_to_default,183,0,Sid::Field::KIND_UINT, (unsigned short) (size_t) &reinterpret_cast<MsgcontactContact*>(base_address)->mood_timestamp,0} } },
                /*126*/ { { {&d1field_equals_default,&d1set_field_to_default,184,0,Sid::Field::KIND_STRING, (unsigned short) (size_t) &reinterpret_cast<MsgcontactContact*>(base_address)->assigned_phone1,0} } },
                /*127*/ { { {&d1field_equals_default,&d1set_field_to_default,185,0,Sid::Field::KIND_STRING, (unsigned short) (size_t) &reinterpret_cast<MsgcontactContact*>(base_address)->assigned_phone1_label,0} } },
                /*128*/ { { {&d1field_equals_default,&d1set_field_to_default,186,0,Sid::Field::KIND_STRING, (unsigned short) (size_t) &reinterpret_cast<MsgcontactContact*>(base_address)->assigned_phone2,0} } },
                /*129*/ { { {&d1field_equals_default,&d1set_field_to_default,187,0,Sid::Field::KIND_STRING, (unsigned short) (size_t) &reinterpret_cast<MsgcontactContact*>(base_address)->assigned_phone2_label,0} } },
                /*130*/ { { {&d1field_equals_default,&d1set_field_to_default,188,0,Sid::Field::KIND_STRING, (unsigned short) (size_t) &reinterpret_cast<MsgcontactContact*>(base_address)->assigned_phone3,0} } },
                /*131*/ { { {&d1field_equals_default,&d1set_field_to_default,189,0,Sid::Field::KIND_STRING, (unsigned short) (size_t) &reinterpret_cast<MsgcontactContact*>(base_address)->assigned_phone3_label,0} } },
                /*132*/ { { {&d9field_equals_default,&d9set_field_to_default,202,0,Sid::Field::KIND_ENUM, (unsigned short) (size_t) &reinterpret_cast<MsgcontactContact*>(base_address)->type,0} } },
                /*133*/ { { {&d1field_equals_default,&d1set_field_to_default,205,0,Sid::Field::KIND_XML, (unsigned short) (size_t) &reinterpret_cast<MsgcontactContact*>(base_address)->rich_mood_text,0} } },
                /*** MsgcontactGetContactTypeRequest */
                /*134*/ { { {&d1field_equals_default,&d1set_field_to_default,1,Sid::Field::FLD_FIRST,Sid::Field::KIND_STRING, MsgcontactGetContactTypeRequest::END,0} } },
                /*** MsgcontactGetContactTypeResponse */
                /*135*/ { { {&d9field_equals_default,&d9set_field_to_default,1,Sid::Field::FLD_FIRST,Sid::Field::KIND_ENUM, MsgcontactGetContactTypeResponse::END,0} } },
                /*** MsgcontactGetContactRequest */
                /*136*/ { { {&d1field_equals_default,&d1set_field_to_default,1,Sid::Field::FLD_FIRST,Sid::Field::KIND_STRING, MsgcontactGetContactRequest::END,0} } },
                /*** MsgcontactGetContactResponse */
                /*137*/ { { {&d7field_equals_default,&d7set_field_to_default,2,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgcontactGetContactResponse::END,2} } },
                /*** MsgcontactFindContactByPstnNumberRequest */
                /*138*/ { { {&d1field_equals_default,&d1set_field_to_default,1,Sid::Field::FLD_FIRST,Sid::Field::KIND_STRING, MsgcontactFindContactByPstnNumberRequest::END,0} } },
                /*** MsgcontactFindContactByPstnNumberResponse */
                /*139*/ { { {&d3field_equals_default,&d3set_field_to_default,1,Sid::Field::FLD_FIRST,Sid::Field::KIND_BOOLEAN, MsgcontactFindContactByPstnNumberResponse::END,0} } },
                /*140*/ { { {&d7field_equals_default,&d7set_field_to_default,2,0,Sid::Field::KIND_OBJECTID, (unsigned short) (size_t) &reinterpret_cast<MsgcontactFindContactByPstnNumberResponse*>(base_address)->contact,2} } },
                /*141*/ { { {&d8field_equals_default,&d8set_field_to_default,3,0,Sid::Field::KIND_UINT, (unsigned short) (size_t) &reinterpret_cast<MsgcontactFindContactByPstnNumberResponse*>(base_address)->foundInKey,0} } },
                /*** MsgcontactGetIdentityTypeRequest */
                /*142*/ { { {&d1field_equals_default,&d1set_field_to_default,1,Sid::Field::FLD_FIRST,Sid::Field::KIND_STRING, MsgcontactGetIdentityTypeRequest::END,0} } },
                /*** MsgcontactGetIdentityTypeResponse */
                /*143*/ { { {&d9field_equals_default,&d9set_field_to_default,1,Sid::Field::FLD_FIRST,Sid::Field::KIND_ENUM, MsgcontactGetIdentityTypeResponse::END,0} } },
                /*** MsgcontactNormalizeIdentityRequest */
                /*144*/ { { {&d1field_equals_default,&d1set_field_to_default,1,Sid::Field::FLD_FIRST,Sid::Field::KIND_STRING, MsgcontactNormalizeIdentityRequest::END,0} } },
                /*145*/ { { {&d12field_equals_default,&d12set_field_to_default,2,0,Sid::Field::KIND_BOOLEAN, (unsigned short) (size_t) &reinterpret_cast<MsgcontactNormalizeIdentityRequest*>(base_address)->isNewSkypeName,0} } },                /*** MsgcontactNormalizeIdentityResponse */
                /*146*/ { { {&d9field_equals_default,&d9set_field_to_default,1,Sid::Field::FLD_FIRST,Sid::Field::KIND_ENUM, MsgcontactNormalizeIdentityResponse::END,0} } },
                /*147*/ { { {&d1field_equals_default,&d1set_field_to_default,2,0,Sid::Field::KIND_STRING, (unsigned short) (size_t) &reinterpret_cast<MsgcontactNormalizeIdentityResponse*>(base_address)->normalized,0} } },
                /*** MsgcontactNormalizePSTNWithCountryRequest */
                /*148*/ { { {&d1field_equals_default,&d1set_field_to_default,1,Sid::Field::FLD_FIRST,Sid::Field::KIND_STRING, MsgcontactNormalizePSTNWithCountryRequest::END,0} } },
                /*149*/ { { {&d8field_equals_default,&d8set_field_to_default,2,0,Sid::Field::KIND_UINT, (unsigned short) (size_t) &reinterpret_cast<MsgcontactNormalizePSTNWithCountryRequest*>(base_address)->countryPrefix,0} } },
                /*** MsgcontactNormalizePSTNWithCountryResponse */
                /*150*/ { { {&d9field_equals_default,&d9set_field_to_default,1,Sid::Field::FLD_FIRST,Sid::Field::KIND_ENUM, MsgcontactNormalizePSTNWithCountryResponse::END,0} } },
                /*151*/ { { {&d1field_equals_default,&d1set_field_to_default,2,0,Sid::Field::KIND_STRING, (unsigned short) (size_t) &reinterpret_cast<MsgcontactNormalizePSTNWithCountryResponse*>(base_address)->normalized,0} } },
                /*** MsgcontactOnContactOnlineAppearance */
                /*152*/ { { {&d7field_equals_default,&d7set_field_to_default,1,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgcontactOnContactOnlineAppearance::END,2} } },
                /*** MsgcontactOnContactGoneOffline */
                /*153*/ { { {&d7field_equals_default,&d7set_field_to_default,1,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgcontactOnContactGoneOffline::END,2} } },
                /*** MsgcontactsearchContactSearchAddMinAgeTermRequest */
                /*154*/ { { {&d14field_equals_default,&d14set_field_to_default,0,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgcontactsearchContactSearchAddMinAgeTermRequest::END,1} } },
                /*155*/ { { {&d8field_equals_default,&d8set_field_to_default,1,0,Sid::Field::KIND_UINT, (unsigned short) (size_t) &reinterpret_cast<MsgcontactsearchContactSearchAddMinAgeTermRequest*>(base_address)->min_age_in_years,0} } },
                /*156*/ { { {&d12field_equals_default,&d12set_field_to_default,2,0,Sid::Field::KIND_BOOLEAN, (unsigned short) (size_t) &reinterpret_cast<MsgcontactsearchContactSearchAddMinAgeTermRequest*>(base_address)->add_to_subs,0} } },
                /*** MsgcontactsearchContactSearchAddMinAgeTermResponse */
                /*157*/ { { {&d3field_equals_default,&d3set_field_to_default,1,Sid::Field::FLD_FIRST,Sid::Field::KIND_BOOLEAN, MsgcontactsearchContactSearchAddMinAgeTermResponse::END,0} } },
                /*** MsgcontactsearchContactSearchAddMaxAgeTermRequest */
                /*158*/ { { {&d14field_equals_default,&d14set_field_to_default,0,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgcontactsearchContactSearchAddMaxAgeTermRequest::END,1} } },
                /*159*/ { { {&d8field_equals_default,&d8set_field_to_default,1,0,Sid::Field::KIND_UINT, (unsigned short) (size_t) &reinterpret_cast<MsgcontactsearchContactSearchAddMaxAgeTermRequest*>(base_address)->max_age_in_years,0} } },
                /*160*/ { { {&d12field_equals_default,&d12set_field_to_default,2,0,Sid::Field::KIND_BOOLEAN, (unsigned short) (size_t) &reinterpret_cast<MsgcontactsearchContactSearchAddMaxAgeTermRequest*>(base_address)->add_to_subs,0} } },
                /*** MsgcontactsearchContactSearchAddMaxAgeTermResponse */
                /*161*/ { { {&d3field_equals_default,&d3set_field_to_default,1,Sid::Field::FLD_FIRST,Sid::Field::KIND_BOOLEAN, MsgcontactsearchContactSearchAddMaxAgeTermResponse::END,0} } },
                /*** MsgcontactsearchContactSearchAddEmailTermRequest */
                /*162*/ { { {&d14field_equals_default,&d14set_field_to_default,0,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgcontactsearchContactSearchAddEmailTermRequest::END,1} } },
                /*163*/ { { {&d1field_equals_default,&d1set_field_to_default,1,0,Sid::Field::KIND_STRING, (unsigned short) (size_t) &reinterpret_cast<MsgcontactsearchContactSearchAddEmailTermRequest*>(base_address)->email,0} } },
                /*164*/ { { {&d12field_equals_default,&d12set_field_to_default,2,0,Sid::Field::KIND_BOOLEAN, (unsigned short) (size_t) &reinterpret_cast<MsgcontactsearchContactSearchAddEmailTermRequest*>(base_address)->add_to_subs,0} } },
                /*** MsgcontactsearchContactSearchAddEmailTermResponse */
                /*165*/ { { {&d3field_equals_default,&d3set_field_to_default,1,Sid::Field::FLD_FIRST,Sid::Field::KIND_BOOLEAN, MsgcontactsearchContactSearchAddEmailTermResponse::END,0} } },
                /*** MsgcontactsearchContactSearchAddLanguageTermRequest */
                /*166*/ { { {&d14field_equals_default,&d14set_field_to_default,0,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgcontactsearchContactSearchAddLanguageTermRequest::END,1} } },
                /*167*/ { { {&d1field_equals_default,&d1set_field_to_default,1,0,Sid::Field::KIND_STRING, (unsigned short) (size_t) &reinterpret_cast<MsgcontactsearchContactSearchAddLanguageTermRequest*>(base_address)->language,0} } },
                /*168*/ { { {&d12field_equals_default,&d12set_field_to_default,2,0,Sid::Field::KIND_BOOLEAN, (unsigned short) (size_t) &reinterpret_cast<MsgcontactsearchContactSearchAddLanguageTermRequest*>(base_address)->add_to_subs,0} } },
                /*** MsgcontactsearchContactSearchAddLanguageTermResponse */
                /*169*/ { { {&d3field_equals_default,&d3set_field_to_default,1,Sid::Field::FLD_FIRST,Sid::Field::KIND_BOOLEAN, MsgcontactsearchContactSearchAddLanguageTermResponse::END,0} } },
                /*** MsgcontactsearchContactSearchAddStrTermRequest */
                /*170*/ { { {&d14field_equals_default,&d14set_field_to_default,0,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgcontactsearchContactSearchAddStrTermRequest::END,1} } },
                /*171*/ { { {&d9field_equals_default,&d9set_field_to_default,1,0,Sid::Field::KIND_ENUM, (unsigned short) (size_t) &reinterpret_cast<MsgcontactsearchContactSearchAddStrTermRequest*>(base_address)->prop,0} } },
                /*172*/ { { {&d9field_equals_default,&d9set_field_to_default,2,0,Sid::Field::KIND_ENUM, (unsigned short) (size_t) &reinterpret_cast<MsgcontactsearchContactSearchAddStrTermRequest*>(base_address)->cond,0} } },
                /*173*/ { { {&d1field_equals_default,&d1set_field_to_default,3,0,Sid::Field::KIND_STRING, (unsigned short) (size_t) &reinterpret_cast<MsgcontactsearchContactSearchAddStrTermRequest*>(base_address)->value,0} } },
                /*174*/ { { {&d12field_equals_default,&d12set_field_to_default,4,0,Sid::Field::KIND_BOOLEAN, (unsigned short) (size_t) &reinterpret_cast<MsgcontactsearchContactSearchAddStrTermRequest*>(base_address)->add_to_subs,0} } },
                /*** MsgcontactsearchContactSearchAddStrTermResponse */
                /*175*/ { { {&d3field_equals_default,&d3set_field_to_default,1,Sid::Field::FLD_FIRST,Sid::Field::KIND_BOOLEAN, MsgcontactsearchContactSearchAddStrTermResponse::END,0} } },
                /*** MsgcontactsearchContactSearchAddIntTermRequest */
                /*176*/ { { {&d14field_equals_default,&d14set_field_to_default,0,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgcontactsearchContactSearchAddIntTermRequest::END,1} } },
                /*177*/ { { {&d9field_equals_default,&d9set_field_to_default,1,0,Sid::Field::KIND_ENUM, (unsigned short) (size_t) &reinterpret_cast<MsgcontactsearchContactSearchAddIntTermRequest*>(base_address)->prop,0} } },
                /*178*/ { { {&d9field_equals_default,&d9set_field_to_default,2,0,Sid::Field::KIND_ENUM, (unsigned short) (size_t) &reinterpret_cast<MsgcontactsearchContactSearchAddIntTermRequest*>(base_address)->cond,0} } },
                /*179*/ { { {&d8field_equals_default,&d8set_field_to_default,3,0,Sid::Field::KIND_UINT, (unsigned short) (size_t) &reinterpret_cast<MsgcontactsearchContactSearchAddIntTermRequest*>(base_address)->value,0} } },                /*180*/ { { {&d12field_equals_default,&d12set_field_to_default,4,0,Sid::Field::KIND_BOOLEAN, (unsigned short) (size_t) &reinterpret_cast<MsgcontactsearchContactSearchAddIntTermRequest*>(base_address)->add_to_subs,0} } },
                /*** MsgcontactsearchContactSearchAddIntTermResponse */
                /*181*/ { { {&d3field_equals_default,&d3set_field_to_default,1,Sid::Field::FLD_FIRST,Sid::Field::KIND_BOOLEAN, MsgcontactsearchContactSearchAddIntTermResponse::END,0} } },
                /*** MsgcontactsearchContactSearchAddOrRequest */
                /*182*/ { { {&d14field_equals_default,&d14set_field_to_default,0,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgcontactsearchContactSearchAddOrRequest::END,1} } },
                /*** MsgcontactsearchContactSearchIsValidRequest */
                /*183*/ { { {&d14field_equals_default,&d14set_field_to_default,0,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgcontactsearchContactSearchIsValidRequest::END,1} } },
                /*** MsgcontactsearchContactSearchIsValidResponse */
                /*184*/ { { {&d3field_equals_default,&d3set_field_to_default,1,Sid::Field::FLD_FIRST,Sid::Field::KIND_BOOLEAN, MsgcontactsearchContactSearchIsValidResponse::END,0} } },
                /*** MsgcontactsearchContactSearchSubmitRequest */
                /*185*/ { { {&d14field_equals_default,&d14set_field_to_default,0,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgcontactsearchContactSearchSubmitRequest::END,1} } },
                /*** MsgcontactsearchContactSearchExtendRequest */
                /*186*/ { { {&d14field_equals_default,&d14set_field_to_default,0,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgcontactsearchContactSearchExtendRequest::END,1} } },
                /*** MsgcontactsearchContactSearchReleaseRequest */
                /*187*/ { { {&d14field_equals_default,&d14set_field_to_default,0,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgcontactsearchContactSearchReleaseRequest::END,1} } },
                /*** MsgcontactsearchContactSearchGetResultsRequest */
                /*188*/ { { {&d14field_equals_default,&d14set_field_to_default,0,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgcontactsearchContactSearchGetResultsRequest::END,1} } },
                /*189*/ { { {&d8field_equals_default,&d8set_field_to_default,1,0,Sid::Field::KIND_UINT, (unsigned short) (size_t) &reinterpret_cast<MsgcontactsearchContactSearchGetResultsRequest*>(base_address)->from,0} } },
                /*190*/ { { {&d15field_equals_default,&d15set_field_to_default,2,0,Sid::Field::KIND_UINT, (unsigned short) (size_t) &reinterpret_cast<MsgcontactsearchContactSearchGetResultsRequest*>(base_address)->count,0} } },
                /*** MsgcontactsearchContactSearchGetResultsResponse */
                /*191*/ { { {&d6field_equals_default,&d6set_field_to_default,1,Sid::Field::FLD_FIRST|Sid::Field::FLD_LIST,Sid::Field::KIND_OBJECTID, MsgcontactsearchContactSearchGetResultsResponse::END,2} } },
                { { { reinterpret_cast<bool(*)(const void*)>(&d6append),reinterpret_cast<void(*)(void*)>(&d6iterate),0,0,0,0,0}}},
                /*** MsgcontactsearchContactSearchOnNewResult */
                /*193*/ { { {&d14field_equals_default,&d14set_field_to_default,0,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgcontactsearchContactSearchOnNewResult::END,1} } },
                /*194*/ { { {&d7field_equals_default,&d7set_field_to_default,1,0,Sid::Field::KIND_OBJECTID, (unsigned short) (size_t) &reinterpret_cast<MsgcontactsearchContactSearchOnNewResult*>(base_address)->contact,2} } },
                /*195*/ { { {&d8field_equals_default,&d8set_field_to_default,2,0,Sid::Field::KIND_UINT, (unsigned short) (size_t) &reinterpret_cast<MsgcontactsearchContactSearchOnNewResult*>(base_address)->rankValue,0} } },
                /*** MsgcontactsearchContactSearch */
                /*196*/ { { {&d9field_equals_default,&d9set_field_to_default,200,Sid::Field::FLD_FIRST,Sid::Field::KIND_ENUM, MsgcontactsearchContactSearch::END,0} } },
                /*** MsgcontactsearchGetOptimalAgeRangesResponse */
                /*197*/ { { {&d16field_equals_default,&d16set_field_to_default,1,Sid::Field::FLD_FIRST|Sid::Field::FLD_LIST,Sid::Field::KIND_UINT, MsgcontactsearchGetOptimalAgeRangesResponse::END,0} } },
                { { { reinterpret_cast<bool(*)(const void*)>(&d16append),reinterpret_cast<void(*)(void*)>(&d16iterate),0,0,0,0,0}}},
                /*** MsgcontactsearchCreateContactSearchResponse */
                /*199*/ { { {&d14field_equals_default,&d14set_field_to_default,1,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgcontactsearchCreateContactSearchResponse::END,1} } },
                /*** MsgcontactsearchCreateBasicContactSearchRequest */
                /*200*/ { { {&d1field_equals_default,&d1set_field_to_default,1,Sid::Field::FLD_FIRST,Sid::Field::KIND_STRING, MsgcontactsearchCreateBasicContactSearchRequest::END,0} } },
                /*** MsgcontactsearchCreateBasicContactSearchResponse */
                /*201*/ { { {&d14field_equals_default,&d14set_field_to_default,1,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgcontactsearchCreateBasicContactSearchResponse::END,1} } },
                /*** MsgcontactsearchCreateIdentitySearchRequest */
                /*202*/ { { {&d1field_equals_default,&d1set_field_to_default,1,Sid::Field::FLD_FIRST,Sid::Field::KIND_STRING, MsgcontactsearchCreateIdentitySearchRequest::END,0} } },
                /*** MsgcontactsearchCreateIdentitySearchResponse */
                /*203*/ { { {&d14field_equals_default,&d14set_field_to_default,1,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgcontactsearchCreateIdentitySearchResponse::END,1} } },
                /*** MsgconversationParticipantCanSetRankToRequest */
                /*204*/ { { {&d17field_equals_default,&d17set_field_to_default,0,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgconversationParticipantCanSetRankToRequest::END,19} } },
                /*205*/ { { {&d9field_equals_default,&d9set_field_to_default,1,0,Sid::Field::KIND_ENUM, (unsigned short) (size_t) &reinterpret_cast<MsgconversationParticipantCanSetRankToRequest*>(base_address)->rank,0} } },
                /*** MsgconversationParticipantCanSetRankToResponse */
                /*206*/ { { {&d3field_equals_default,&d3set_field_to_default,1,Sid::Field::FLD_FIRST,Sid::Field::KIND_BOOLEAN, MsgconversationParticipantCanSetRankToResponse::END,0} } },
                /*** MsgconversationParticipantSetRankToRequest */
                /*207*/ { { {&d17field_equals_default,&d17set_field_to_default,0,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgconversationParticipantSetRankToRequest::END,19} } },
                /*208*/ { { {&d9field_equals_default,&d9set_field_to_default,1,0,Sid::Field::KIND_ENUM, (unsigned short) (size_t) &reinterpret_cast<MsgconversationParticipantSetRankToRequest*>(base_address)->rank,0} } },
                /*** MsgconversationParticipantRingRequest */
                /*209*/ { { {&d17field_equals_default,&d17set_field_to_default,0,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgconversationParticipantRingRequest::END,19} } },
                /*210*/ { { {&d1field_equals_default,&d1set_field_to_default,1,0,Sid::Field::KIND_STRING, (unsigned short) (size_t) &reinterpret_cast<MsgconversationParticipantRingRequest*>(base_address)->identityToUse,0} } },
                /*211*/ { { {&d12field_equals_default,&d12set_field_to_default,2,0,Sid::Field::KIND_BOOLEAN, (unsigned short) (size_t) &reinterpret_cast<MsgconversationParticipantRingRequest*>(base_address)->videoCall,0} } },
                /*212*/ { { {&d8field_equals_default,&d8set_field_to_default,3,0,Sid::Field::KIND_UINT, (unsigned short) (size_t) &reinterpret_cast<MsgconversationParticipantRingRequest*>(base_address)->nrofRedials,0} } },
                /*213*/ { { {&d8field_equals_default,&d8set_field_to_default,4,0,Sid::Field::KIND_UINT, (unsigned short) (size_t) &reinterpret_cast<MsgconversationParticipantRingRequest*>(base_address)->redialPeriod,0} } },
                /*214*/ { { {&d12field_equals_default,&d12set_field_to_default,5,0,Sid::Field::KIND_BOOLEAN, (unsigned short) (size_t) &reinterpret_cast<MsgconversationParticipantRingRequest*>(base_address)->autoStartVM,0} } },                /*215*/ { { {&d1field_equals_default,&d1set_field_to_default,6,0,Sid::Field::KIND_STRING, (unsigned short) (size_t) &reinterpret_cast<MsgconversationParticipantRingRequest*>(base_address)->origin,0} } },
                /*** MsgconversationParticipantRingItRequest */
                /*216*/ { { {&d17field_equals_default,&d17set_field_to_default,0,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgconversationParticipantRingItRequest::END,19} } },
                /*** MsgconversationParticipantSetLiveIdentityToUseRequest */
                /*217*/ { { {&d17field_equals_default,&d17set_field_to_default,0,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgconversationParticipantSetLiveIdentityToUseRequest::END,19} } },
                /*218*/ { { {&d1field_equals_default,&d1set_field_to_default,1,0,Sid::Field::KIND_STRING, (unsigned short) (size_t) &reinterpret_cast<MsgconversationParticipantSetLiveIdentityToUseRequest*>(base_address)->identityToUse,0} } },
                /*** MsgconversationParticipantGetVideoRequest */
                /*219*/ { { {&d17field_equals_default,&d17set_field_to_default,0,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgconversationParticipantGetVideoRequest::END,19} } },
                /*** MsgconversationParticipantGetVideoResponse */
                /*220*/ { { {&d18field_equals_default,&d18set_field_to_default,1,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgconversationParticipantGetVideoResponse::END,11} } },
                /*** MsgconversationParticipantHangupRequest */
                /*221*/ { { {&d17field_equals_default,&d17set_field_to_default,0,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgconversationParticipantHangupRequest::END,19} } },
                /*** MsgconversationParticipantRetireRequest */
                /*222*/ { { {&d17field_equals_default,&d17set_field_to_default,0,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgconversationParticipantRetireRequest::END,19} } },
                /*** MsgconversationParticipantOnIncomingDTMF */
                /*223*/ { { {&d17field_equals_default,&d17set_field_to_default,0,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgconversationParticipantOnIncomingDTMF::END,19} } },
                /*224*/ { { {&d9field_equals_default,&d9set_field_to_default,1,0,Sid::Field::KIND_ENUM, (unsigned short) (size_t) &reinterpret_cast<MsgconversationParticipantOnIncomingDTMF*>(base_address)->dtmf,0} } },
                /*** MsgconversationParticipant */
                /*225*/ { { {&d5field_equals_default,&d5set_field_to_default,930,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgconversationParticipant::END,18} } },
                /*226*/ { { {&d1field_equals_default,&d1set_field_to_default,931,0,Sid::Field::KIND_STRING, (unsigned short) (size_t) &reinterpret_cast<MsgconversationParticipant*>(base_address)->identity,0} } },
                /*227*/ { { {&d9field_equals_default,&d9set_field_to_default,932,0,Sid::Field::KIND_ENUM, (unsigned short) (size_t) &reinterpret_cast<MsgconversationParticipant*>(base_address)->rank,0} } },
                /*228*/ { { {&d9field_equals_default,&d9set_field_to_default,933,0,Sid::Field::KIND_ENUM, (unsigned short) (size_t) &reinterpret_cast<MsgconversationParticipant*>(base_address)->requested_rank,0} } },
                /*229*/ { { {&d9field_equals_default,&d9set_field_to_default,934,0,Sid::Field::KIND_ENUM, (unsigned short) (size_t) &reinterpret_cast<MsgconversationParticipant*>(base_address)->text_status,0} } },
                /*230*/ { { {&d9field_equals_default,&d9set_field_to_default,935,0,Sid::Field::KIND_ENUM, (unsigned short) (size_t) &reinterpret_cast<MsgconversationParticipant*>(base_address)->voice_status,0} } },
                /*231*/ { { {&d9field_equals_default,&d9set_field_to_default,936,0,Sid::Field::KIND_ENUM, (unsigned short) (size_t) &reinterpret_cast<MsgconversationParticipant*>(base_address)->video_status,0} } },
                /*232*/ { { {&d1field_equals_default,&d1set_field_to_default,938,0,Sid::Field::KIND_STRING, (unsigned short) (size_t) &reinterpret_cast<MsgconversationParticipant*>(base_address)->live_price_for_me,0} } },
                /*233*/ { { {&d8field_equals_default,&d8set_field_to_default,939,0,Sid::Field::KIND_UINT, (unsigned short) (size_t) &reinterpret_cast<MsgconversationParticipant*>(base_address)->live_start_timestamp,0} } },
                /*234*/ { { {&d8field_equals_default,&d8set_field_to_default,941,0,Sid::Field::KIND_UINT, (unsigned short) (size_t) &reinterpret_cast<MsgconversationParticipant*>(base_address)->sound_level,0} } },
                /*235*/ { { {&d1field_equals_default,&d1set_field_to_default,942,0,Sid::Field::KIND_STRING, (unsigned short) (size_t) &reinterpret_cast<MsgconversationParticipant*>(base_address)->debuginfo,0} } },
                /*236*/ { { {&d1field_equals_default,&d1set_field_to_default,943,0,Sid::Field::KIND_STRING, (unsigned short) (size_t) &reinterpret_cast<MsgconversationParticipant*>(base_address)->live_identity,0} } },
                /*237*/ { { {&d1field_equals_default,&d1set_field_to_default,947,0,Sid::Field::KIND_STRING, (unsigned short) (size_t) &reinterpret_cast<MsgconversationParticipant*>(base_address)->last_voice_error,0} } },
                /*238*/ { { {&d1field_equals_default,&d1set_field_to_default,948,0,Sid::Field::KIND_STRING, (unsigned short) (size_t) &reinterpret_cast<MsgconversationParticipant*>(base_address)->live_fwd_identities,0} } },
                /*239*/ { { {&d1field_equals_default,&d1set_field_to_default,949,0,Sid::Field::KIND_STRING, (unsigned short) (size_t) &reinterpret_cast<MsgconversationParticipant*>(base_address)->quality_problems,0} } },
                /*240*/ { { {&d9field_equals_default,&d9set_field_to_default,950,0,Sid::Field::KIND_ENUM, (unsigned short) (size_t) &reinterpret_cast<MsgconversationParticipant*>(base_address)->live_type,0} } },
                /*241*/ { { {&d1field_equals_default,&d1set_field_to_default,951,0,Sid::Field::KIND_STRING, (unsigned short) (size_t) &reinterpret_cast<MsgconversationParticipant*>(base_address)->live_country,0} } },
                /*242*/ { { {&d1field_equals_default,&d1set_field_to_default,952,0,Sid::Field::KIND_STRING, (unsigned short) (size_t) &reinterpret_cast<MsgconversationParticipant*>(base_address)->transferred_by,0} } },
                /*243*/ { { {&d1field_equals_default,&d1set_field_to_default,953,0,Sid::Field::KIND_STRING, (unsigned short) (size_t) &reinterpret_cast<MsgconversationParticipant*>(base_address)->transferred_to,0} } },
                /*244*/ { { {&d1field_equals_default,&d1set_field_to_default,954,0,Sid::Field::KIND_STRING, (unsigned short) (size_t) &reinterpret_cast<MsgconversationParticipant*>(base_address)->adder,0} } },
                /*** MsgconversationConversationSetOptionRequest */
                /*245*/ { { {&d5field_equals_default,&d5set_field_to_default,0,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgconversationConversationSetOptionRequest::END,18} } },
                /*246*/ { { {&d9field_equals_default,&d9set_field_to_default,1,0,Sid::Field::KIND_ENUM, (unsigned short) (size_t) &reinterpret_cast<MsgconversationConversationSetOptionRequest*>(base_address)->propKey,0} } },
                /*247*/ { { {&d8field_equals_default,&d8set_field_to_default,2,0,Sid::Field::KIND_UINT, (unsigned short) (size_t) &reinterpret_cast<MsgconversationConversationSetOptionRequest*>(base_address)->value,0} } },
                /*** MsgconversationConversationSetTopicRequest */
                /*248*/ { { {&d5field_equals_default,&d5set_field_to_default,0,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgconversationConversationSetTopicRequest::END,18} } },
                /*249*/ { { {&d1field_equals_default,&d1set_field_to_default,1,0,Sid::Field::KIND_STRING, (unsigned short) (size_t) &reinterpret_cast<MsgconversationConversationSetTopicRequest*>(base_address)->topic,0} } },
                /*250*/ { { {&d12field_equals_default,&d12set_field_to_default,2,0,Sid::Field::KIND_BOOLEAN, (unsigned short) (size_t) &reinterpret_cast<MsgconversationConversationSetTopicRequest*>(base_address)->isXML,0} } },                /*** MsgconversationConversationSetGuidelinesRequest */
                /*251*/ { { {&d5field_equals_default,&d5set_field_to_default,0,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgconversationConversationSetGuidelinesRequest::END,18} } },
                /*252*/ { { {&d1field_equals_default,&d1set_field_to_default,1,0,Sid::Field::KIND_STRING, (unsigned short) (size_t) &reinterpret_cast<MsgconversationConversationSetGuidelinesRequest*>(base_address)->guidelines,0} } },
                /*253*/ { { {&d12field_equals_default,&d12set_field_to_default,2,0,Sid::Field::KIND_BOOLEAN, (unsigned short) (size_t) &reinterpret_cast<MsgconversationConversationSetGuidelinesRequest*>(base_address)->isXML,0} } },
                /*** MsgconversationConversationSetPictureRequest */
                /*254*/ { { {&d5field_equals_default,&d5set_field_to_default,0,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgconversationConversationSetPictureRequest::END,18} } },
                /*255*/ { { {&d11field_equals_default,&d11set_field_to_default,1,0,Sid::Field::KIND_BINARY, (unsigned short) (size_t) &reinterpret_cast<MsgconversationConversationSetPictureRequest*>(base_address)->jpeg,0} } },
                /*** MsgconversationConversationSpawnConferenceRequest */
                /*256*/ { { {&d5field_equals_default,&d5set_field_to_default,0,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgconversationConversationSpawnConferenceRequest::END,18} } },
                /*257*/ { { {&d19field_equals_default,&d19set_field_to_default,1,Sid::Field::FLD_LIST,Sid::Field::KIND_STRING, (unsigned short) (size_t) &reinterpret_cast<MsgconversationConversationSpawnConferenceRequest*>(base_address)->identitiesToAdd,0} } },
                { { { reinterpret_cast<bool(*)(const void*)>(&d19append),reinterpret_cast<void(*)(void*)>(&d19iterate),0,0,0,0,0}}},
                /*** MsgconversationConversationSpawnConferenceResponse */
                /*259*/ { { {&d5field_equals_default,&d5set_field_to_default,1,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgconversationConversationSpawnConferenceResponse::END,18} } },
                /*** MsgconversationConversationAddConsumersRequest */
                /*260*/ { { {&d5field_equals_default,&d5set_field_to_default,0,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgconversationConversationAddConsumersRequest::END,18} } },
                /*261*/ { { {&d19field_equals_default,&d19set_field_to_default,1,Sid::Field::FLD_LIST,Sid::Field::KIND_STRING, (unsigned short) (size_t) &reinterpret_cast<MsgconversationConversationAddConsumersRequest*>(base_address)->identities,0} } },
                { { { reinterpret_cast<bool(*)(const void*)>(&d19append),reinterpret_cast<void(*)(void*)>(&d19iterate),0,0,0,0,0}}},
                /*** MsgconversationConversationAssimilateRequest */
                /*263*/ { { {&d5field_equals_default,&d5set_field_to_default,0,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgconversationConversationAssimilateRequest::END,18} } },
                /*264*/ { { {&d5field_equals_default,&d5set_field_to_default,1,0,Sid::Field::KIND_OBJECTID, (unsigned short) (size_t) &reinterpret_cast<MsgconversationConversationAssimilateRequest*>(base_address)->otherConversation,18} } },
                /*** MsgconversationConversationAssimilateResponse */
                /*265*/ { { {&d5field_equals_default,&d5set_field_to_default,1,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgconversationConversationAssimilateResponse::END,18} } },
                /*** MsgconversationConversationJoinLiveSessionRequest */
                /*266*/ { { {&d5field_equals_default,&d5set_field_to_default,0,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgconversationConversationJoinLiveSessionRequest::END,18} } },
                /*267*/ { { {&d1field_equals_default,&d1set_field_to_default,1,0,Sid::Field::KIND_STRING, (unsigned short) (size_t) &reinterpret_cast<MsgconversationConversationJoinLiveSessionRequest*>(base_address)->accessToken,0} } },
                /*** MsgconversationConversationRingOthersRequest */
                /*268*/ { { {&d5field_equals_default,&d5set_field_to_default,0,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgconversationConversationRingOthersRequest::END,18} } },
                /*269*/ { { {&d19field_equals_default,&d19set_field_to_default,1,Sid::Field::FLD_LIST,Sid::Field::KIND_STRING, (unsigned short) (size_t) &reinterpret_cast<MsgconversationConversationRingOthersRequest*>(base_address)->identities,0} } },
                { { { reinterpret_cast<bool(*)(const void*)>(&d19append),reinterpret_cast<void(*)(void*)>(&d19iterate),0,0,0,0,0}}},
                /*271*/ { { {&d12field_equals_default,&d12set_field_to_default,2,0,Sid::Field::KIND_BOOLEAN, (unsigned short) (size_t) &reinterpret_cast<MsgconversationConversationRingOthersRequest*>(base_address)->videoCall,0} } },
                /*272*/ { { {&d1field_equals_default,&d1set_field_to_default,3,0,Sid::Field::KIND_STRING, (unsigned short) (size_t) &reinterpret_cast<MsgconversationConversationRingOthersRequest*>(base_address)->origin,0} } },
                /*** MsgconversationConversationMuteMyMicrophoneRequest */
                /*273*/ { { {&d5field_equals_default,&d5set_field_to_default,0,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgconversationConversationMuteMyMicrophoneRequest::END,18} } },
                /*** MsgconversationConversationUnmuteMyMicrophoneRequest */
                /*274*/ { { {&d5field_equals_default,&d5set_field_to_default,0,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgconversationConversationUnmuteMyMicrophoneRequest::END,18} } },
                /*** MsgconversationConversationHoldMyLiveSessionRequest */
                /*275*/ { { {&d5field_equals_default,&d5set_field_to_default,0,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgconversationConversationHoldMyLiveSessionRequest::END,18} } },
                /*** MsgconversationConversationResumeMyLiveSessionRequest */
                /*276*/ { { {&d5field_equals_default,&d5set_field_to_default,0,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgconversationConversationResumeMyLiveSessionRequest::END,18} } },
                /*** MsgconversationConversationLeaveLiveSessionRequest */
                /*277*/ { { {&d5field_equals_default,&d5set_field_to_default,0,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgconversationConversationLeaveLiveSessionRequest::END,18} } },
                /*278*/ { { {&d12field_equals_default,&d12set_field_to_default,1,0,Sid::Field::KIND_BOOLEAN, (unsigned short) (size_t) &reinterpret_cast<MsgconversationConversationLeaveLiveSessionRequest*>(base_address)->postVoiceAutoresponse,0} } },
                /*** MsgconversationConversationStartVoiceMessageRequest */
                /*279*/ { { {&d5field_equals_default,&d5set_field_to_default,0,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgconversationConversationStartVoiceMessageRequest::END,18} } },
                /*** MsgconversationConversationTransferLiveSessionRequest */
                /*280*/ { { {&d5field_equals_default,&d5set_field_to_default,0,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgconversationConversationTransferLiveSessionRequest::END,18} } },
                /*281*/ { { {&d19field_equals_default,&d19set_field_to_default,1,Sid::Field::FLD_LIST,Sid::Field::KIND_STRING, (unsigned short) (size_t) &reinterpret_cast<MsgconversationConversationTransferLiveSessionRequest*>(base_address)->identities,0} } },
                { { { reinterpret_cast<bool(*)(const void*)>(&d19append),reinterpret_cast<void(*)(void*)>(&d19iterate),0,0,0,0,0}}},
                /*283*/ { { {&d1field_equals_default,&d1set_field_to_default,2,0,Sid::Field::KIND_STRING, (unsigned short) (size_t) &reinterpret_cast<MsgconversationConversationTransferLiveSessionRequest*>(base_address)->transferTopic,0} } },
                /*** MsgconversationConversationCanTransferLiveSessionRequest */
                /*284*/ { { {&d5field_equals_default,&d5set_field_to_default,0,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgconversationConversationCanTransferLiveSessionRequest::END,18} } },                /*285*/ { { {&d1field_equals_default,&d1set_field_to_default,1,0,Sid::Field::KIND_STRING, (unsigned short) (size_t) &reinterpret_cast<MsgconversationConversationCanTransferLiveSessionRequest*>(base_address)->identity,0} } },
                /*** MsgconversationConversationCanTransferLiveSessionResponse */
                /*286*/ { { {&d3field_equals_default,&d3set_field_to_default,1,Sid::Field::FLD_FIRST,Sid::Field::KIND_BOOLEAN, MsgconversationConversationCanTransferLiveSessionResponse::END,0} } },
                /*** MsgconversationConversationSendDTMFRequest */
                /*287*/ { { {&d5field_equals_default,&d5set_field_to_default,0,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgconversationConversationSendDTMFRequest::END,18} } },
                /*288*/ { { {&d9field_equals_default,&d9set_field_to_default,1,0,Sid::Field::KIND_ENUM, (unsigned short) (size_t) &reinterpret_cast<MsgconversationConversationSendDTMFRequest*>(base_address)->dtmf,0} } },
                /*289*/ { { {&d20field_equals_default,&d20set_field_to_default,2,0,Sid::Field::KIND_UINT, (unsigned short) (size_t) &reinterpret_cast<MsgconversationConversationSendDTMFRequest*>(base_address)->lengthInMS,0} } },
                /*** MsgconversationConversationStopSendDTMFRequest */
                /*290*/ { { {&d5field_equals_default,&d5set_field_to_default,0,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgconversationConversationStopSendDTMFRequest::END,18} } },
                /*** MsgconversationConversationSetMyTextStatusToRequest */
                /*291*/ { { {&d5field_equals_default,&d5set_field_to_default,0,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgconversationConversationSetMyTextStatusToRequest::END,18} } },
                /*292*/ { { {&d9field_equals_default,&d9set_field_to_default,1,0,Sid::Field::KIND_ENUM, (unsigned short) (size_t) &reinterpret_cast<MsgconversationConversationSetMyTextStatusToRequest*>(base_address)->status,0} } },
                /*** MsgconversationConversationPostTextRequest */
                /*293*/ { { {&d5field_equals_default,&d5set_field_to_default,0,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgconversationConversationPostTextRequest::END,18} } },
                /*294*/ { { {&d1field_equals_default,&d1set_field_to_default,1,0,Sid::Field::KIND_STRING, (unsigned short) (size_t) &reinterpret_cast<MsgconversationConversationPostTextRequest*>(base_address)->text,0} } },
                /*295*/ { { {&d12field_equals_default,&d12set_field_to_default,2,0,Sid::Field::KIND_BOOLEAN, (unsigned short) (size_t) &reinterpret_cast<MsgconversationConversationPostTextRequest*>(base_address)->isXML,0} } },
                /*** MsgconversationConversationPostTextResponse */
                /*296*/ { { {&d21field_equals_default,&d21set_field_to_default,1,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgconversationConversationPostTextResponse::END,9} } },
                /*** MsgconversationConversationPostContactsRequest */
                /*297*/ { { {&d5field_equals_default,&d5set_field_to_default,0,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgconversationConversationPostContactsRequest::END,18} } },
                /*298*/ { { {&d6field_equals_default,&d6set_field_to_default,1,Sid::Field::FLD_LIST,Sid::Field::KIND_OBJECTID, (unsigned short) (size_t) &reinterpret_cast<MsgconversationConversationPostContactsRequest*>(base_address)->contacts,2} } },
                { { { reinterpret_cast<bool(*)(const void*)>(&d6append),reinterpret_cast<void(*)(void*)>(&d6iterate),0,0,0,0,0}}},
                /*** MsgconversationConversationPostFilesRequest */
                /*300*/ { { {&d5field_equals_default,&d5set_field_to_default,0,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgconversationConversationPostFilesRequest::END,18} } },
                /*301*/ { { {&d22field_equals_default,&d22set_field_to_default,1,Sid::Field::FLD_LIST,Sid::Field::KIND_FILENAME, (unsigned short) (size_t) &reinterpret_cast<MsgconversationConversationPostFilesRequest*>(base_address)->paths,0} } },
                { { { reinterpret_cast<bool(*)(const void*)>(&d22append),reinterpret_cast<void(*)(void*)>(&d22iterate),0,0,0,0,0}}},
                /*303*/ { { {&d1field_equals_default,&d1set_field_to_default,2,0,Sid::Field::KIND_STRING, (unsigned short) (size_t) &reinterpret_cast<MsgconversationConversationPostFilesRequest*>(base_address)->body,0} } },
                /*** MsgconversationConversationPostFilesResponse */
                /*304*/ { { {&d9field_equals_default,&d9set_field_to_default,1,Sid::Field::FLD_FIRST,Sid::Field::KIND_ENUM, MsgconversationConversationPostFilesResponse::END,0} } },
                /*305*/ { { {&d23field_equals_default,&d23set_field_to_default,2,0,Sid::Field::KIND_FILENAME, (unsigned short) (size_t) &reinterpret_cast<MsgconversationConversationPostFilesResponse*>(base_address)->error_file,0} } },
                /*** MsgconversationConversationPostVoiceMessageRequest */
                /*306*/ { { {&d5field_equals_default,&d5set_field_to_default,0,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgconversationConversationPostVoiceMessageRequest::END,18} } },
                /*307*/ { { {&d24field_equals_default,&d24set_field_to_default,1,0,Sid::Field::KIND_OBJECTID, (unsigned short) (size_t) &reinterpret_cast<MsgconversationConversationPostVoiceMessageRequest*>(base_address)->voicemail,7} } },
                /*308*/ { { {&d1field_equals_default,&d1set_field_to_default,2,0,Sid::Field::KIND_STRING, (unsigned short) (size_t) &reinterpret_cast<MsgconversationConversationPostVoiceMessageRequest*>(base_address)->body,0} } },
                /*** MsgconversationConversationPostSMSRequest */
                /*309*/ { { {&d5field_equals_default,&d5set_field_to_default,0,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgconversationConversationPostSMSRequest::END,18} } },
                /*310*/ { { {&d25field_equals_default,&d25set_field_to_default,1,0,Sid::Field::KIND_OBJECTID, (unsigned short) (size_t) &reinterpret_cast<MsgconversationConversationPostSMSRequest*>(base_address)->sms,12} } },
                /*311*/ { { {&d1field_equals_default,&d1set_field_to_default,2,0,Sid::Field::KIND_STRING, (unsigned short) (size_t) &reinterpret_cast<MsgconversationConversationPostSMSRequest*>(base_address)->body,0} } },
                /*** MsgconversationConversationGetJoinBlobRequest */
                /*312*/ { { {&d5field_equals_default,&d5set_field_to_default,0,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgconversationConversationGetJoinBlobRequest::END,18} } },
                /*** MsgconversationConversationGetJoinBlobResponse */
                /*313*/ { { {&d1field_equals_default,&d1set_field_to_default,1,Sid::Field::FLD_FIRST,Sid::Field::KIND_STRING, MsgconversationConversationGetJoinBlobResponse::END,0} } },
                /*** MsgconversationConversationJoinRequest */
                /*314*/ { { {&d5field_equals_default,&d5set_field_to_default,0,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgconversationConversationJoinRequest::END,18} } },
                /*** MsgconversationConversationEnterPasswordRequest */
                /*315*/ { { {&d5field_equals_default,&d5set_field_to_default,0,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgconversationConversationEnterPasswordRequest::END,18} } },
                /*316*/ { { {&d1field_equals_default,&d1set_field_to_default,1,0,Sid::Field::KIND_STRING, (unsigned short) (size_t) &reinterpret_cast<MsgconversationConversationEnterPasswordRequest*>(base_address)->password,0} } },
                /*** MsgconversationConversationSetPasswordRequest */
                /*317*/ { { {&d5field_equals_default,&d5set_field_to_default,0,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgconversationConversationSetPasswordRequest::END,18} } },
                /*318*/ { { {&d1field_equals_default,&d1set_field_to_default,1,0,Sid::Field::KIND_STRING, (unsigned short) (size_t) &reinterpret_cast<MsgconversationConversationSetPasswordRequest*>(base_address)->password,0} } },
                /*319*/ { { {&d1field_equals_default,&d1set_field_to_default,2,0,Sid::Field::KIND_STRING, (unsigned short) (size_t) &reinterpret_cast<MsgconversationConversationSetPasswordRequest*>(base_address)->hint,0} } },                /*** MsgconversationConversationRetireFromRequest */
                /*320*/ { { {&d5field_equals_default,&d5set_field_to_default,0,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgconversationConversationRetireFromRequest::END,18} } },
                /*** MsgconversationConversationDeleteRequest */
                /*321*/ { { {&d5field_equals_default,&d5set_field_to_default,0,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgconversationConversationDeleteRequest::END,18} } },
                /*** MsgconversationConversationRenameToRequest */
                /*322*/ { { {&d5field_equals_default,&d5set_field_to_default,0,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgconversationConversationRenameToRequest::END,18} } },
                /*323*/ { { {&d1field_equals_default,&d1set_field_to_default,1,0,Sid::Field::KIND_STRING, (unsigned short) (size_t) &reinterpret_cast<MsgconversationConversationRenameToRequest*>(base_address)->name,0} } },
                /*** MsgconversationConversationSetBookmarkRequest */
                /*324*/ { { {&d5field_equals_default,&d5set_field_to_default,0,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgconversationConversationSetBookmarkRequest::END,18} } },
                /*325*/ { { {&d3field_equals_default,&d3set_field_to_default,1,0,Sid::Field::KIND_BOOLEAN, (unsigned short) (size_t) &reinterpret_cast<MsgconversationConversationSetBookmarkRequest*>(base_address)->bookmark,0} } },
                /*** MsgconversationConversationSetAlertStringRequest */
                /*326*/ { { {&d5field_equals_default,&d5set_field_to_default,0,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgconversationConversationSetAlertStringRequest::END,18} } },
                /*327*/ { { {&d1field_equals_default,&d1set_field_to_default,1,0,Sid::Field::KIND_STRING, (unsigned short) (size_t) &reinterpret_cast<MsgconversationConversationSetAlertStringRequest*>(base_address)->alertString,0} } },
                /*** MsgconversationConversationRemoveFromInboxRequest */
                /*328*/ { { {&d5field_equals_default,&d5set_field_to_default,0,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgconversationConversationRemoveFromInboxRequest::END,18} } },
                /*** MsgconversationConversationAddToInboxRequest */
                /*329*/ { { {&d5field_equals_default,&d5set_field_to_default,0,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgconversationConversationAddToInboxRequest::END,18} } },
                /*330*/ { { {&d8field_equals_default,&d8set_field_to_default,1,0,Sid::Field::KIND_UINT, (unsigned short) (size_t) &reinterpret_cast<MsgconversationConversationAddToInboxRequest*>(base_address)->timestamp,0} } },
                /*** MsgconversationConversationSetConsumedHorizonRequest */
                /*331*/ { { {&d5field_equals_default,&d5set_field_to_default,0,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgconversationConversationSetConsumedHorizonRequest::END,18} } },
                /*332*/ { { {&d8field_equals_default,&d8set_field_to_default,1,0,Sid::Field::KIND_UINT, (unsigned short) (size_t) &reinterpret_cast<MsgconversationConversationSetConsumedHorizonRequest*>(base_address)->timestamp,0} } },
                /*333*/ { { {&d12field_equals_default,&d12set_field_to_default,2,0,Sid::Field::KIND_BOOLEAN, (unsigned short) (size_t) &reinterpret_cast<MsgconversationConversationSetConsumedHorizonRequest*>(base_address)->also_unconsume,0} } },
                /*** MsgconversationConversationMarkUnreadRequest */
                /*334*/ { { {&d5field_equals_default,&d5set_field_to_default,0,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgconversationConversationMarkUnreadRequest::END,18} } },
                /*** MsgconversationConversationIsMemberOfRequest */
                /*335*/ { { {&d5field_equals_default,&d5set_field_to_default,0,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgconversationConversationIsMemberOfRequest::END,18} } },
                /*336*/ { { {&d2field_equals_default,&d2set_field_to_default,1,0,Sid::Field::KIND_OBJECTID, (unsigned short) (size_t) &reinterpret_cast<MsgconversationConversationIsMemberOfRequest*>(base_address)->group,10} } },
                /*** MsgconversationConversationIsMemberOfResponse */
                /*337*/ { { {&d3field_equals_default,&d3set_field_to_default,1,Sid::Field::FLD_FIRST,Sid::Field::KIND_BOOLEAN, MsgconversationConversationIsMemberOfResponse::END,0} } },
                /*** MsgconversationConversationGetParticipantsRequest */
                /*338*/ { { {&d5field_equals_default,&d5set_field_to_default,0,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgconversationConversationGetParticipantsRequest::END,18} } },
                /*339*/ { { {&d9field_equals_default,&d9set_field_to_default,1,0,Sid::Field::KIND_ENUM, (unsigned short) (size_t) &reinterpret_cast<MsgconversationConversationGetParticipantsRequest*>(base_address)->filter,0} } },
                /*** MsgconversationConversationGetParticipantsResponse */
                /*340*/ { { {&d26field_equals_default,&d26set_field_to_default,1,Sid::Field::FLD_FIRST|Sid::Field::FLD_LIST,Sid::Field::KIND_OBJECTID, MsgconversationConversationGetParticipantsResponse::END,19} } },
                { { { reinterpret_cast<bool(*)(const void*)>(&d26append),reinterpret_cast<void(*)(void*)>(&d26iterate),0,0,0,0,0}}},
                /*** MsgconversationConversationGetLastMessagesRequest */
                /*342*/ { { {&d5field_equals_default,&d5set_field_to_default,0,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgconversationConversationGetLastMessagesRequest::END,18} } },
                /*343*/ { { {&d8field_equals_default,&d8set_field_to_default,1,0,Sid::Field::KIND_UINT, (unsigned short) (size_t) &reinterpret_cast<MsgconversationConversationGetLastMessagesRequest*>(base_address)->requireTimestamp,0} } },
                /*** MsgconversationConversationGetLastMessagesResponse */
                /*344*/ { { {&d27field_equals_default,&d27set_field_to_default,1,Sid::Field::FLD_FIRST|Sid::Field::FLD_LIST,Sid::Field::KIND_OBJECTID, MsgconversationConversationGetLastMessagesResponse::END,9} } },
                { { { reinterpret_cast<bool(*)(const void*)>(&d27append),reinterpret_cast<void(*)(void*)>(&d27iterate),0,0,0,0,0}}},
                /*346*/ { { {&d27field_equals_default,&d27set_field_to_default,2,Sid::Field::FLD_LIST,Sid::Field::KIND_OBJECTID, (unsigned short) (size_t) &reinterpret_cast<MsgconversationConversationGetLastMessagesResponse*>(base_address)->unconsumedMessages,9} } },
                { { { reinterpret_cast<bool(*)(const void*)>(&d27append),reinterpret_cast<void(*)(void*)>(&d27iterate),0,0,0,0,0}}},
                /*** MsgconversationConversationFindMessageRequest */
                /*348*/ { { {&d5field_equals_default,&d5set_field_to_default,0,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgconversationConversationFindMessageRequest::END,18} } },
                /*349*/ { { {&d1field_equals_default,&d1set_field_to_default,1,0,Sid::Field::KIND_STRING, (unsigned short) (size_t) &reinterpret_cast<MsgconversationConversationFindMessageRequest*>(base_address)->text,0} } },
                /*350*/ { { {&d15field_equals_default,&d15set_field_to_default,2,0,Sid::Field::KIND_UINT, (unsigned short) (size_t) &reinterpret_cast<MsgconversationConversationFindMessageRequest*>(base_address)->fromTimestampUp,0} } },
                /*** MsgconversationConversationFindMessageResponse */
                /*351*/ { { {&d21field_equals_default,&d21set_field_to_default,1,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgconversationConversationFindMessageResponse::END,9} } },
                /*** MsgconversationConversationOnParticipantListChange */
                /*352*/ { { {&d5field_equals_default,&d5set_field_to_default,0,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgconversationConversationOnParticipantListChange::END,18} } },
                /*** MsgconversationConversationOnMessage */
                /*353*/ { { {&d5field_equals_default,&d5set_field_to_default,0,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgconversationConversationOnMessage::END,18} } },                /*354*/ { { {&d21field_equals_default,&d21set_field_to_default,1,0,Sid::Field::KIND_OBJECTID, (unsigned short) (size_t) &reinterpret_cast<MsgconversationConversationOnMessage*>(base_address)->message,9} } },
                /*** MsgconversationConversationOnSpawnConference */
                /*355*/ { { {&d5field_equals_default,&d5set_field_to_default,0,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgconversationConversationOnSpawnConference::END,18} } },
                /*356*/ { { {&d5field_equals_default,&d5set_field_to_default,1,0,Sid::Field::KIND_OBJECTID, (unsigned short) (size_t) &reinterpret_cast<MsgconversationConversationOnSpawnConference*>(base_address)->spawned,18} } },
                /*** MsgconversationConversation */
                /*357*/ { { {&d9field_equals_default,&d9set_field_to_default,902,Sid::Field::FLD_FIRST,Sid::Field::KIND_ENUM, MsgconversationConversation::END,0} } },
                /*358*/ { { {&d1field_equals_default,&d1set_field_to_default,903,0,Sid::Field::KIND_STRING, (unsigned short) (size_t) &reinterpret_cast<MsgconversationConversation*>(base_address)->creator,0} } },
                /*359*/ { { {&d8field_equals_default,&d8set_field_to_default,904,0,Sid::Field::KIND_UINT, (unsigned short) (size_t) &reinterpret_cast<MsgconversationConversation*>(base_address)->creation_timestamp,0} } },
                /*360*/ { { {&d9field_equals_default,&d9set_field_to_default,906,0,Sid::Field::KIND_ENUM, (unsigned short) (size_t) &reinterpret_cast<MsgconversationConversation*>(base_address)->opt_entry_level_rank,0} } },
                /*361*/ { { {&d3field_equals_default,&d3set_field_to_default,907,0,Sid::Field::KIND_BOOLEAN, (unsigned short) (size_t) &reinterpret_cast<MsgconversationConversation*>(base_address)->opt_disclose_history,0} } },
                /*362*/ { { {&d9field_equals_default,&d9set_field_to_default,909,0,Sid::Field::KIND_ENUM, (unsigned short) (size_t) &reinterpret_cast<MsgconversationConversation*>(base_address)->opt_admin_only_activities,0} } },
                /*363*/ { { {&d1field_equals_default,&d1set_field_to_default,910,0,Sid::Field::KIND_STRING, (unsigned short) (size_t) &reinterpret_cast<MsgconversationConversation*>(base_address)->meta_name,0} } },
                /*364*/ { { {&d1field_equals_default,&d1set_field_to_default,911,0,Sid::Field::KIND_XML, (unsigned short) (size_t) &reinterpret_cast<MsgconversationConversation*>(base_address)->meta_topic,0} } },
                /*365*/ { { {&d1field_equals_default,&d1set_field_to_default,913,0,Sid::Field::KIND_XML, (unsigned short) (size_t) &reinterpret_cast<MsgconversationConversation*>(base_address)->meta_guidelines,0} } },
                /*366*/ { { {&d11field_equals_default,&d11set_field_to_default,914,0,Sid::Field::KIND_BINARY, (unsigned short) (size_t) &reinterpret_cast<MsgconversationConversation*>(base_address)->meta_picture,0} } },
                /*367*/ { { {&d5field_equals_default,&d5set_field_to_default,915,0,Sid::Field::KIND_OBJECTID, (unsigned short) (size_t) &reinterpret_cast<MsgconversationConversation*>(base_address)->spawned_from_convo_id,18} } },
                /*368*/ { { {&d1field_equals_default,&d1set_field_to_default,918,0,Sid::Field::KIND_STRING, (unsigned short) (size_t) &reinterpret_cast<MsgconversationConversation*>(base_address)->live_host,0} } },
                /*369*/ { { {&d9field_equals_default,&d9set_field_to_default,919,0,Sid::Field::KIND_ENUM, (unsigned short) (size_t) &reinterpret_cast<MsgconversationConversation*>(base_address)->my_status,0} } },
                /*370*/ { { {&d1field_equals_default,&d1set_field_to_default,920,0,Sid::Field::KIND_STRING, (unsigned short) (size_t) &reinterpret_cast<MsgconversationConversation*>(base_address)->alert_string,0} } },
                /*371*/ { { {&d3field_equals_default,&d3set_field_to_default,921,0,Sid::Field::KIND_BOOLEAN, (unsigned short) (size_t) &reinterpret_cast<MsgconversationConversation*>(base_address)->is_bookmarked,0} } },
                /*372*/ { { {&d3field_equals_default,&d3set_field_to_default,922,0,Sid::Field::KIND_BOOLEAN, (unsigned short) (size_t) &reinterpret_cast<MsgconversationConversation*>(base_address)->opt_joining_enabled,0} } },
                /*373*/ { { {&d1field_equals_default,&d1set_field_to_default,924,0,Sid::Field::KIND_STRING, (unsigned short) (size_t) &reinterpret_cast<MsgconversationConversation*>(base_address)->displayname,0} } },
                /*374*/ { { {&d1field_equals_default,&d1set_field_to_default,925,0,Sid::Field::KIND_STRING, (unsigned short) (size_t) &reinterpret_cast<MsgconversationConversation*>(base_address)->given_displayname,0} } },
                /*375*/ { { {&d9field_equals_default,&d9set_field_to_default,927,0,Sid::Field::KIND_ENUM, (unsigned short) (size_t) &reinterpret_cast<MsgconversationConversation*>(base_address)->local_livestatus,0} } },
                /*376*/ { { {&d8field_equals_default,&d8set_field_to_default,928,0,Sid::Field::KIND_UINT, (unsigned short) (size_t) &reinterpret_cast<MsgconversationConversation*>(base_address)->inbox_timestamp,0} } },
                /*377*/ { { {&d3field_equals_default,&d3set_field_to_default,970,0,Sid::Field::KIND_BOOLEAN, (unsigned short) (size_t) &reinterpret_cast<MsgconversationConversation*>(base_address)->unconsumed_messages_voice,0} } },
                /*378*/ { { {&d24field_equals_default,&d24set_field_to_default,971,0,Sid::Field::KIND_OBJECTID, (unsigned short) (size_t) &reinterpret_cast<MsgconversationConversation*>(base_address)->active_vm_id,7} } },
                /*379*/ { { {&d1field_equals_default,&d1set_field_to_default,972,0,Sid::Field::KIND_STRING, (unsigned short) (size_t) &reinterpret_cast<MsgconversationConversation*>(base_address)->identity,0} } },
                /*380*/ { { {&d21field_equals_default,&d21set_field_to_default,973,0,Sid::Field::KIND_OBJECTID, (unsigned short) (size_t) &reinterpret_cast<MsgconversationConversation*>(base_address)->inbox_message_id,9} } },
                /*381*/ { { {&d8field_equals_default,&d8set_field_to_default,974,0,Sid::Field::KIND_UINT, (unsigned short) (size_t) &reinterpret_cast<MsgconversationConversation*>(base_address)->live_start_timestamp,0} } },
                /*382*/ { { {&d8field_equals_default,&d8set_field_to_default,975,0,Sid::Field::KIND_UINT, (unsigned short) (size_t) &reinterpret_cast<MsgconversationConversation*>(base_address)->unconsumed_suppressed_messages,0} } },
                /*383*/ { { {&d8field_equals_default,&d8set_field_to_default,976,0,Sid::Field::KIND_UINT, (unsigned short) (size_t) &reinterpret_cast<MsgconversationConversation*>(base_address)->unconsumed_normal_messages,0} } },
                /*384*/ { { {&d8field_equals_default,&d8set_field_to_default,977,0,Sid::Field::KIND_UINT, (unsigned short) (size_t) &reinterpret_cast<MsgconversationConversation*>(base_address)->unconsumed_elevated_messages,0} } },
                /*385*/ { { {&d8field_equals_default,&d8set_field_to_default,979,0,Sid::Field::KIND_UINT, (unsigned short) (size_t) &reinterpret_cast<MsgconversationConversation*>(base_address)->consumption_horizon,0} } },
                /*386*/ { { {&d1field_equals_default,&d1set_field_to_default,980,0,Sid::Field::KIND_STRING, (unsigned short) (size_t) &reinterpret_cast<MsgconversationConversation*>(base_address)->passwordhint,0} } },
                /*387*/ { { {&d8field_equals_default,&d8set_field_to_default,981,0,Sid::Field::KIND_UINT, (unsigned short) (size_t) &reinterpret_cast<MsgconversationConversation*>(base_address)->last_activity_timestamp,0} } },
                /*388*/ { { {&d3field_equals_default,&d3set_field_to_default,996,0,Sid::Field::KIND_BOOLEAN, (unsigned short) (size_t) &reinterpret_cast<MsgconversationConversation*>(base_address)->live_is_muted,0} } },
                /*** MsgconversationCreateConferenceResponse */
                /*389*/ { { {&d5field_equals_default,&d5set_field_to_default,1,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgconversationCreateConferenceResponse::END,18} } },
                /*** MsgconversationGetConversationByIdentityRequest */
                /*390*/ { { {&d1field_equals_default,&d1set_field_to_default,1,Sid::Field::FLD_FIRST,Sid::Field::KIND_STRING, MsgconversationGetConversationByIdentityRequest::END,0} } },                /*** MsgconversationGetConversationByIdentityResponse */
                /*391*/ { { {&d5field_equals_default,&d5set_field_to_default,1,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgconversationGetConversationByIdentityResponse::END,18} } },
                /*** MsgconversationGetConversationByParticipantsRequest */
                /*392*/ { { {&d19field_equals_default,&d19set_field_to_default,1,Sid::Field::FLD_FIRST|Sid::Field::FLD_LIST,Sid::Field::KIND_STRING, MsgconversationGetConversationByParticipantsRequest::END,0} } },
                { { { reinterpret_cast<bool(*)(const void*)>(&d19append),reinterpret_cast<void(*)(void*)>(&d19iterate),0,0,0,0,0}}},
                /*394*/ { { {&d12field_equals_default,&d12set_field_to_default,2,0,Sid::Field::KIND_BOOLEAN, (unsigned short) (size_t) &reinterpret_cast<MsgconversationGetConversationByParticipantsRequest*>(base_address)->createIfNonExisting,0} } },
                /*395*/ { { {&d12field_equals_default,&d12set_field_to_default,3,0,Sid::Field::KIND_BOOLEAN, (unsigned short) (size_t) &reinterpret_cast<MsgconversationGetConversationByParticipantsRequest*>(base_address)->ignoreBookmarkedOrNamed,0} } },
                /*** MsgconversationGetConversationByParticipantsResponse */
                /*396*/ { { {&d5field_equals_default,&d5set_field_to_default,1,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgconversationGetConversationByParticipantsResponse::END,18} } },
                /*** MsgconversationGetConversationByBlobRequest */
                /*397*/ { { {&d1field_equals_default,&d1set_field_to_default,1,Sid::Field::FLD_FIRST,Sid::Field::KIND_STRING, MsgconversationGetConversationByBlobRequest::END,0} } },
                /*398*/ { { {&d13field_equals_default,&d13set_field_to_default,2,0,Sid::Field::KIND_BOOLEAN, (unsigned short) (size_t) &reinterpret_cast<MsgconversationGetConversationByBlobRequest*>(base_address)->alsoJoin,0} } },
                /*** MsgconversationGetConversationByBlobResponse */
                /*399*/ { { {&d5field_equals_default,&d5set_field_to_default,1,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgconversationGetConversationByBlobResponse::END,18} } },
                /*** MsgconversationGetConversationListRequest */
                /*400*/ { { {&d9field_equals_default,&d9set_field_to_default,1,Sid::Field::FLD_FIRST,Sid::Field::KIND_ENUM, MsgconversationGetConversationListRequest::END,0} } },
                /*** MsgconversationGetConversationListResponse */
                /*401*/ { { {&d4field_equals_default,&d4set_field_to_default,1,Sid::Field::FLD_FIRST|Sid::Field::FLD_LIST,Sid::Field::KIND_OBJECTID, MsgconversationGetConversationListResponse::END,18} } },
                { { { reinterpret_cast<bool(*)(const void*)>(&d4append),reinterpret_cast<void(*)(void*)>(&d4iterate),0,0,0,0,0}}},
                /*** MsgconversationOnConversationListChange */
                /*403*/ { { {&d5field_equals_default,&d5set_field_to_default,1,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgconversationOnConversationListChange::END,18} } },
                /*404*/ { { {&d9field_equals_default,&d9set_field_to_default,2,0,Sid::Field::KIND_ENUM, (unsigned short) (size_t) &reinterpret_cast<MsgconversationOnConversationListChange*>(base_address)->type,0} } },
                /*405*/ { { {&d3field_equals_default,&d3set_field_to_default,3,0,Sid::Field::KIND_BOOLEAN, (unsigned short) (size_t) &reinterpret_cast<MsgconversationOnConversationListChange*>(base_address)->added,0} } },
                /*** MsgconversationMessageCanEditRequest */
                /*406*/ { { {&d21field_equals_default,&d21set_field_to_default,0,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgconversationMessageCanEditRequest::END,9} } },
                /*** MsgconversationMessageCanEditResponse */
                /*407*/ { { {&d3field_equals_default,&d3set_field_to_default,1,Sid::Field::FLD_FIRST,Sid::Field::KIND_BOOLEAN, MsgconversationMessageCanEditResponse::END,0} } },
                /*** MsgconversationMessageEditRequest */
                /*408*/ { { {&d21field_equals_default,&d21set_field_to_default,0,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgconversationMessageEditRequest::END,9} } },
                /*409*/ { { {&d1field_equals_default,&d1set_field_to_default,1,0,Sid::Field::KIND_STRING, (unsigned short) (size_t) &reinterpret_cast<MsgconversationMessageEditRequest*>(base_address)->newText,0} } },
                /*410*/ { { {&d12field_equals_default,&d12set_field_to_default,2,0,Sid::Field::KIND_BOOLEAN, (unsigned short) (size_t) &reinterpret_cast<MsgconversationMessageEditRequest*>(base_address)->isXML,0} } },
                /*** MsgconversationMessageGetContactsRequest */
                /*411*/ { { {&d21field_equals_default,&d21set_field_to_default,0,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgconversationMessageGetContactsRequest::END,9} } },
                /*** MsgconversationMessageGetContactsResponse */
                /*412*/ { { {&d6field_equals_default,&d6set_field_to_default,1,Sid::Field::FLD_FIRST|Sid::Field::FLD_LIST,Sid::Field::KIND_OBJECTID, MsgconversationMessageGetContactsResponse::END,2} } },
                { { { reinterpret_cast<bool(*)(const void*)>(&d6append),reinterpret_cast<void(*)(void*)>(&d6iterate),0,0,0,0,0}}},
                /*** MsgconversationMessageGetTransfersRequest */
                /*414*/ { { {&d21field_equals_default,&d21set_field_to_default,0,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgconversationMessageGetTransfersRequest::END,9} } },
                /*** MsgconversationMessageGetTransfersResponse */
                /*415*/ { { {&d28field_equals_default,&d28set_field_to_default,1,Sid::Field::FLD_FIRST|Sid::Field::FLD_LIST,Sid::Field::KIND_OBJECTID, MsgconversationMessageGetTransfersResponse::END,6} } },
                { { { reinterpret_cast<bool(*)(const void*)>(&d28append),reinterpret_cast<void(*)(void*)>(&d28iterate),0,0,0,0,0}}},
                /*** MsgconversationMessageGetVoiceMessageRequest */
                /*417*/ { { {&d21field_equals_default,&d21set_field_to_default,0,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgconversationMessageGetVoiceMessageRequest::END,9} } },
                /*** MsgconversationMessageGetVoiceMessageResponse */
                /*418*/ { { {&d24field_equals_default,&d24set_field_to_default,1,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgconversationMessageGetVoiceMessageResponse::END,7} } },
                /*** MsgconversationMessageGetSMSRequest */
                /*419*/ { { {&d21field_equals_default,&d21set_field_to_default,0,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgconversationMessageGetSMSRequest::END,9} } },
                /*** MsgconversationMessageGetSMSResponse */
                /*420*/ { { {&d25field_equals_default,&d25set_field_to_default,1,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgconversationMessageGetSMSResponse::END,12} } },
                /*** MsgconversationMessageDeleteLocallyRequest */
                /*421*/ { { {&d21field_equals_default,&d21set_field_to_default,0,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgconversationMessageDeleteLocallyRequest::END,9} } },
                /*** MsgconversationMessage */
                /*422*/ { { {&d1field_equals_default,&d1set_field_to_default,120,Sid::Field::FLD_FIRST,Sid::Field::KIND_STRING, MsgconversationMessage::END,0} } },
                /*423*/ { { {&d8field_equals_default,&d8set_field_to_default,121,0,Sid::Field::KIND_UINT, (unsigned short) (size_t) &reinterpret_cast<MsgconversationMessage*>(base_address)->timestamp,0} } },
                /*424*/ { { {&d1field_equals_default,&d1set_field_to_default,122,0,Sid::Field::KIND_STRING, (unsigned short) (size_t) &reinterpret_cast<MsgconversationMessage*>(base_address)->author,0} } },
                /*425*/ { { {&d1field_equals_default,&d1set_field_to_default,123,0,Sid::Field::KIND_STRING, (unsigned short) (size_t) &reinterpret_cast<MsgconversationMessage*>(base_address)->author_displayname,0} } },
                /*426*/ { { {&d1field_equals_default,&d1set_field_to_default,125,0,Sid::Field::KIND_STRING, (unsigned short) (size_t) &reinterpret_cast<MsgconversationMessage*>(base_address)->identities,0} } },                /*427*/ { { {&d9field_equals_default,&d9set_field_to_default,126,0,Sid::Field::KIND_ENUM, (unsigned short) (size_t) &reinterpret_cast<MsgconversationMessage*>(base_address)->leavereason,0} } },
                /*428*/ { { {&d1field_equals_default,&d1set_field_to_default,127,0,Sid::Field::KIND_XML, (unsigned short) (size_t) &reinterpret_cast<MsgconversationMessage*>(base_address)->body_xml,0} } },
                /*429*/ { { {&d1field_equals_default,&d1set_field_to_default,222,0,Sid::Field::KIND_STRING, (unsigned short) (size_t) &reinterpret_cast<MsgconversationMessage*>(base_address)->edited_by,0} } },
                /*430*/ { { {&d8field_equals_default,&d8set_field_to_default,223,0,Sid::Field::KIND_UINT, (unsigned short) (size_t) &reinterpret_cast<MsgconversationMessage*>(base_address)->edit_timestamp,0} } },
                /*431*/ { { {&d1field_equals_default,&d1set_field_to_default,790,0,Sid::Field::KIND_STRING, (unsigned short) (size_t) &reinterpret_cast<MsgconversationMessage*>(base_address)->originally_meant_for,0} } },
                /*432*/ { { {&d11field_equals_default,&d11set_field_to_default,792,0,Sid::Field::KIND_BINARY, (unsigned short) (size_t) &reinterpret_cast<MsgconversationMessage*>(base_address)->guid,0} } },
                /*433*/ { { {&d5field_equals_default,&d5set_field_to_default,960,0,Sid::Field::KIND_OBJECTID, (unsigned short) (size_t) &reinterpret_cast<MsgconversationMessage*>(base_address)->convo_id,18} } },
                /*434*/ { { {&d9field_equals_default,&d9set_field_to_default,961,0,Sid::Field::KIND_ENUM, (unsigned short) (size_t) &reinterpret_cast<MsgconversationMessage*>(base_address)->type,0} } },
                /*435*/ { { {&d9field_equals_default,&d9set_field_to_default,962,0,Sid::Field::KIND_ENUM, (unsigned short) (size_t) &reinterpret_cast<MsgconversationMessage*>(base_address)->sending_status,0} } },
                /*436*/ { { {&d8field_equals_default,&d8set_field_to_default,963,0,Sid::Field::KIND_UINT, (unsigned short) (size_t) &reinterpret_cast<MsgconversationMessage*>(base_address)->param_key,0} } },
                /*437*/ { { {&d8field_equals_default,&d8set_field_to_default,964,0,Sid::Field::KIND_UINT, (unsigned short) (size_t) &reinterpret_cast<MsgconversationMessage*>(base_address)->param_value,0} } },
                /*438*/ { { {&d1field_equals_default,&d1set_field_to_default,966,0,Sid::Field::KIND_STRING, (unsigned short) (size_t) &reinterpret_cast<MsgconversationMessage*>(base_address)->reason,0} } },
                /*439*/ { { {&d9field_equals_default,&d9set_field_to_default,968,0,Sid::Field::KIND_ENUM, (unsigned short) (size_t) &reinterpret_cast<MsgconversationMessage*>(base_address)->consumption_status,0} } },
                /*440*/ { { {&d8field_equals_default,&d8set_field_to_default,982,0,Sid::Field::KIND_UINT, (unsigned short) (size_t) &reinterpret_cast<MsgconversationMessage*>(base_address)->participant_count,0} } },
                /*** MsgconversationGetMessageByGuidRequest */
                /*441*/ { { {&d11field_equals_default,&d11set_field_to_default,1,Sid::Field::FLD_FIRST,Sid::Field::KIND_BINARY, MsgconversationGetMessageByGuidRequest::END,0} } },
                /*** MsgconversationGetMessageByGuidResponse */
                /*442*/ { { {&d21field_equals_default,&d21set_field_to_default,1,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgconversationGetMessageByGuidResponse::END,9} } },
                /*** MsgconversationOnMessage */
                /*443*/ { { {&d21field_equals_default,&d21set_field_to_default,1,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgconversationOnMessage::END,9} } },
                /*444*/ { { {&d3field_equals_default,&d3set_field_to_default,2,0,Sid::Field::KIND_BOOLEAN, (unsigned short) (size_t) &reinterpret_cast<MsgconversationOnMessage*>(base_address)->changesInboxTimestamp,0} } },
                /*445*/ { { {&d21field_equals_default,&d21set_field_to_default,3,0,Sid::Field::KIND_OBJECTID, (unsigned short) (size_t) &reinterpret_cast<MsgconversationOnMessage*>(base_address)->supersedesHistoryMessage,9} } },
                /*446*/ { { {&d5field_equals_default,&d5set_field_to_default,4,0,Sid::Field::KIND_OBJECTID, (unsigned short) (size_t) &reinterpret_cast<MsgconversationOnMessage*>(base_address)->conversation,18} } },
                /*** MsgvideoVideoSetScreenRequest */
                /*447*/ { { {&d18field_equals_default,&d18set_field_to_default,0,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgvideoVideoSetScreenRequest::END,11} } },
                /*448*/ { { {&d8field_equals_default,&d8set_field_to_default,1,0,Sid::Field::KIND_UINT, (unsigned short) (size_t) &reinterpret_cast<MsgvideoVideoSetScreenRequest*>(base_address)->windowh,0} } },
                /*** MsgvideoVideoStartRequest */
                /*449*/ { { {&d18field_equals_default,&d18set_field_to_default,0,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgvideoVideoStartRequest::END,11} } },
                /*** MsgvideoVideoStopRequest */
                /*450*/ { { {&d18field_equals_default,&d18set_field_to_default,0,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgvideoVideoStopRequest::END,11} } },
                /*** MsgvideoVideoSubmitCaptureRequestRequest */
                /*451*/ { { {&d18field_equals_default,&d18set_field_to_default,0,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgvideoVideoSubmitCaptureRequestRequest::END,11} } },
                /*** MsgvideoVideoSubmitCaptureRequestResponse */
                /*452*/ { { {&d3field_equals_default,&d3set_field_to_default,1,Sid::Field::FLD_FIRST,Sid::Field::KIND_BOOLEAN, MsgvideoVideoSubmitCaptureRequestResponse::END,0} } },
                /*453*/ { { {&d8field_equals_default,&d8set_field_to_default,2,0,Sid::Field::KIND_UINT, (unsigned short) (size_t) &reinterpret_cast<MsgvideoVideoSubmitCaptureRequestResponse*>(base_address)->requestId,0} } },
                /*** MsgvideoVideoOnCaptureRequestCompleted */
                /*454*/ { { {&d18field_equals_default,&d18set_field_to_default,0,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgvideoVideoOnCaptureRequestCompleted::END,11} } },
                /*455*/ { { {&d8field_equals_default,&d8set_field_to_default,1,0,Sid::Field::KIND_UINT, (unsigned short) (size_t) &reinterpret_cast<MsgvideoVideoOnCaptureRequestCompleted*>(base_address)->requestId,0} } },
                /*456*/ { { {&d3field_equals_default,&d3set_field_to_default,2,0,Sid::Field::KIND_BOOLEAN, (unsigned short) (size_t) &reinterpret_cast<MsgvideoVideoOnCaptureRequestCompleted*>(base_address)->isSuccessful,0} } },
                /*457*/ { { {&d11field_equals_default,&d11set_field_to_default,3,0,Sid::Field::KIND_BINARY, (unsigned short) (size_t) &reinterpret_cast<MsgvideoVideoOnCaptureRequestCompleted*>(base_address)->image,0} } },
                /*458*/ { { {&d9field_equals_default,&d9set_field_to_default,4,0,Sid::Field::KIND_INT, (unsigned short) (size_t) &reinterpret_cast<MsgvideoVideoOnCaptureRequestCompleted*>(base_address)->width,0} } },
                /*459*/ { { {&d9field_equals_default,&d9set_field_to_default,5,0,Sid::Field::KIND_INT, (unsigned short) (size_t) &reinterpret_cast<MsgvideoVideoOnCaptureRequestCompleted*>(base_address)->height,0} } },
                /*** MsgvideoVideoSetScreenCaptureRectangleRequest */
                /*460*/ { { {&d18field_equals_default,&d18set_field_to_default,0,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgvideoVideoSetScreenCaptureRectangleRequest::END,11} } },
                /*461*/ { { {&d9field_equals_default,&d9set_field_to_default,1,0,Sid::Field::KIND_INT, (unsigned short) (size_t) &reinterpret_cast<MsgvideoVideoSetScreenCaptureRectangleRequest*>(base_address)->x0,0} } },
                /*462*/ { { {&d9field_equals_default,&d9set_field_to_default,2,0,Sid::Field::KIND_INT, (unsigned short) (size_t) &reinterpret_cast<MsgvideoVideoSetScreenCaptureRectangleRequest*>(base_address)->y0,0} } },
                /*463*/ { { {&d8field_equals_default,&d8set_field_to_default,3,0,Sid::Field::KIND_UINT, (unsigned short) (size_t) &reinterpret_cast<MsgvideoVideoSetScreenCaptureRectangleRequest*>(base_address)->width,0} } },                /*464*/ { { {&d8field_equals_default,&d8set_field_to_default,4,0,Sid::Field::KIND_UINT, (unsigned short) (size_t) &reinterpret_cast<MsgvideoVideoSetScreenCaptureRectangleRequest*>(base_address)->height,0} } },
                /*465*/ { { {&d9field_equals_default,&d9set_field_to_default,5,0,Sid::Field::KIND_INT, (unsigned short) (size_t) &reinterpret_cast<MsgvideoVideoSetScreenCaptureRectangleRequest*>(base_address)->monitorNumber,0} } },
                /*466*/ { { {&d8field_equals_default,&d8set_field_to_default,6,0,Sid::Field::KIND_UINT, (unsigned short) (size_t) &reinterpret_cast<MsgvideoVideoSetScreenCaptureRectangleRequest*>(base_address)->windowHandle,0} } },
                /*** MsgvideoVideoSetRenderRectangleRequest */
                /*467*/ { { {&d18field_equals_default,&d18set_field_to_default,0,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgvideoVideoSetRenderRectangleRequest::END,11} } },
                /*468*/ { { {&d9field_equals_default,&d9set_field_to_default,1,0,Sid::Field::KIND_INT, (unsigned short) (size_t) &reinterpret_cast<MsgvideoVideoSetRenderRectangleRequest*>(base_address)->x0,0} } },
                /*469*/ { { {&d9field_equals_default,&d9set_field_to_default,2,0,Sid::Field::KIND_INT, (unsigned short) (size_t) &reinterpret_cast<MsgvideoVideoSetRenderRectangleRequest*>(base_address)->y0,0} } },
                /*470*/ { { {&d8field_equals_default,&d8set_field_to_default,3,0,Sid::Field::KIND_UINT, (unsigned short) (size_t) &reinterpret_cast<MsgvideoVideoSetRenderRectangleRequest*>(base_address)->width,0} } },
                /*471*/ { { {&d8field_equals_default,&d8set_field_to_default,4,0,Sid::Field::KIND_UINT, (unsigned short) (size_t) &reinterpret_cast<MsgvideoVideoSetRenderRectangleRequest*>(base_address)->height,0} } },
                /*** MsgvideoVideoSelectVideoSourceRequest */
                /*472*/ { { {&d18field_equals_default,&d18set_field_to_default,0,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgvideoVideoSelectVideoSourceRequest::END,11} } },
                /*473*/ { { {&d9field_equals_default,&d9set_field_to_default,1,0,Sid::Field::KIND_ENUM, (unsigned short) (size_t) &reinterpret_cast<MsgvideoVideoSelectVideoSourceRequest*>(base_address)->mediaType,0} } },
                /*474*/ { { {&d1field_equals_default,&d1set_field_to_default,2,0,Sid::Field::KIND_STRING, (unsigned short) (size_t) &reinterpret_cast<MsgvideoVideoSelectVideoSourceRequest*>(base_address)->webcamName,0} } },
                /*475*/ { { {&d1field_equals_default,&d1set_field_to_default,3,0,Sid::Field::KIND_STRING, (unsigned short) (size_t) &reinterpret_cast<MsgvideoVideoSelectVideoSourceRequest*>(base_address)->devicePath,0} } },
                /*476*/ { { {&d12field_equals_default,&d12set_field_to_default,4,0,Sid::Field::KIND_BOOLEAN, (unsigned short) (size_t) &reinterpret_cast<MsgvideoVideoSelectVideoSourceRequest*>(base_address)->updateSetup,0} } },
                /*** MsgvideoVideoGetCurrentVideoDeviceRequest */
                /*477*/ { { {&d18field_equals_default,&d18set_field_to_default,0,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgvideoVideoGetCurrentVideoDeviceRequest::END,11} } },
                /*** MsgvideoVideoGetCurrentVideoDeviceResponse */
                /*478*/ { { {&d9field_equals_default,&d9set_field_to_default,1,Sid::Field::FLD_FIRST,Sid::Field::KIND_ENUM, MsgvideoVideoGetCurrentVideoDeviceResponse::END,0} } },
                /*479*/ { { {&d1field_equals_default,&d1set_field_to_default,2,0,Sid::Field::KIND_STRING, (unsigned short) (size_t) &reinterpret_cast<MsgvideoVideoGetCurrentVideoDeviceResponse*>(base_address)->deviceName,0} } },
                /*480*/ { { {&d1field_equals_default,&d1set_field_to_default,3,0,Sid::Field::KIND_STRING, (unsigned short) (size_t) &reinterpret_cast<MsgvideoVideoGetCurrentVideoDeviceResponse*>(base_address)->devicePath,0} } },
                /*** MsgvideoVideoOnLastFrameCapture */
                /*481*/ { { {&d18field_equals_default,&d18set_field_to_default,0,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgvideoVideoOnLastFrameCapture::END,11} } },
                /*482*/ { { {&d11field_equals_default,&d11set_field_to_default,1,0,Sid::Field::KIND_BINARY, (unsigned short) (size_t) &reinterpret_cast<MsgvideoVideoOnLastFrameCapture*>(base_address)->image,0} } },
                /*483*/ { { {&d8field_equals_default,&d8set_field_to_default,2,0,Sid::Field::KIND_UINT, (unsigned short) (size_t) &reinterpret_cast<MsgvideoVideoOnLastFrameCapture*>(base_address)->width,0} } },
                /*484*/ { { {&d8field_equals_default,&d8set_field_to_default,3,0,Sid::Field::KIND_UINT, (unsigned short) (size_t) &reinterpret_cast<MsgvideoVideoOnLastFrameCapture*>(base_address)->height,0} } },
                /*** MsgvideoVideo */
                /*485*/ { { {&d9field_equals_default,&d9set_field_to_default,130,Sid::Field::FLD_FIRST,Sid::Field::KIND_ENUM, MsgvideoVideo::END,0} } },
                /*486*/ { { {&d1field_equals_default,&d1set_field_to_default,131,0,Sid::Field::KIND_STRING, (unsigned short) (size_t) &reinterpret_cast<MsgvideoVideo*>(base_address)->error,0} } },
                /*487*/ { { {&d1field_equals_default,&d1set_field_to_default,132,0,Sid::Field::KIND_STRING, (unsigned short) (size_t) &reinterpret_cast<MsgvideoVideo*>(base_address)->debuginfo,0} } },
                /*488*/ { { {&d1field_equals_default,&d1set_field_to_default,133,0,Sid::Field::KIND_STRING, (unsigned short) (size_t) &reinterpret_cast<MsgvideoVideo*>(base_address)->dimensions,0} } },
                /*489*/ { { {&d9field_equals_default,&d9set_field_to_default,134,0,Sid::Field::KIND_ENUM, (unsigned short) (size_t) &reinterpret_cast<MsgvideoVideo*>(base_address)->media_type,0} } },
                /*490*/ { { {&d8field_equals_default,&d8set_field_to_default,1104,0,Sid::Field::KIND_UINT, (unsigned short) (size_t) &reinterpret_cast<MsgvideoVideo*>(base_address)->convo_id,0} } },
                /*491*/ { { {&d1field_equals_default,&d1set_field_to_default,1105,0,Sid::Field::KIND_STRING, (unsigned short) (size_t) &reinterpret_cast<MsgvideoVideo*>(base_address)->device_path,0} } },
                /*** MsgvideoGetAvailableVideoDevicesResponse */
                /*492*/ { { {&d19field_equals_default,&d19set_field_to_default,1,Sid::Field::FLD_FIRST|Sid::Field::FLD_LIST,Sid::Field::KIND_STRING, MsgvideoGetAvailableVideoDevicesResponse::END,0} } },
                { { { reinterpret_cast<bool(*)(const void*)>(&d19append),reinterpret_cast<void(*)(void*)>(&d19iterate),0,0,0,0,0}}},
                /*494*/ { { {&d19field_equals_default,&d19set_field_to_default,2,Sid::Field::FLD_LIST,Sid::Field::KIND_STRING, (unsigned short) (size_t) &reinterpret_cast<MsgvideoGetAvailableVideoDevicesResponse*>(base_address)->devicePaths,0} } },
                { { { reinterpret_cast<bool(*)(const void*)>(&d19append),reinterpret_cast<void(*)(void*)>(&d19iterate),0,0,0,0,0}}},
                /*496*/ { { {&d8field_equals_default,&d8set_field_to_default,3,0,Sid::Field::KIND_UINT, (unsigned short) (size_t) &reinterpret_cast<MsgvideoGetAvailableVideoDevicesResponse*>(base_address)->count,0} } },
                /*** MsgvideoHasVideoDeviceCapabilityRequest */
                /*497*/ { { {&d1field_equals_default,&d1set_field_to_default,1,Sid::Field::FLD_FIRST,Sid::Field::KIND_STRING, MsgvideoHasVideoDeviceCapabilityRequest::END,0} } },
                /*498*/ { { {&d1field_equals_default,&d1set_field_to_default,2,0,Sid::Field::KIND_STRING, (unsigned short) (size_t) &reinterpret_cast<MsgvideoHasVideoDeviceCapabilityRequest*>(base_address)->devicePath,0} } },
                /*499*/ { { {&d9field_equals_default,&d9set_field_to_default,3,0,Sid::Field::KIND_ENUM, (unsigned short) (size_t) &reinterpret_cast<MsgvideoHasVideoDeviceCapabilityRequest*>(base_address)->cap,0} } },
                /*** MsgvideoDisplayVideoDeviceTuningDialogRequest */
                /*500*/ { { {&d1field_equals_default,&d1set_field_to_default,1,Sid::Field::FLD_FIRST,Sid::Field::KIND_STRING, MsgvideoDisplayVideoDeviceTuningDialogRequest::END,0} } },
                /*501*/ { { {&d1field_equals_default,&d1set_field_to_default,2,0,Sid::Field::KIND_STRING, (unsigned short) (size_t) &reinterpret_cast<MsgvideoDisplayVideoDeviceTuningDialogRequest*>(base_address)->devicePath,0} } },                /*** MsgvideoGetPreviewVideoRequest */
                /*502*/ { { {&d9field_equals_default,&d9set_field_to_default,1,Sid::Field::FLD_FIRST,Sid::Field::KIND_ENUM, MsgvideoGetPreviewVideoRequest::END,0} } },
                /*503*/ { { {&d1field_equals_default,&d1set_field_to_default,2,0,Sid::Field::KIND_STRING, (unsigned short) (size_t) &reinterpret_cast<MsgvideoGetPreviewVideoRequest*>(base_address)->deviceName,0} } },
                /*504*/ { { {&d1field_equals_default,&d1set_field_to_default,3,0,Sid::Field::KIND_STRING, (unsigned short) (size_t) &reinterpret_cast<MsgvideoGetPreviewVideoRequest*>(base_address)->devicePath,0} } },
                /*** MsgvideoGetPreviewVideoResponse */
                /*505*/ { { {&d18field_equals_default,&d18set_field_to_default,1,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgvideoGetPreviewVideoResponse::END,11} } },
                /*** MsgvideoVideoCommandRequest */
                /*506*/ { { {&d1field_equals_default,&d1set_field_to_default,1,Sid::Field::FLD_FIRST,Sid::Field::KIND_STRING, MsgvideoVideoCommandRequest::END,0} } },
                /*** MsgvideoVideoCommandResponse */
                /*507*/ { { {&d1field_equals_default,&d1set_field_to_default,1,Sid::Field::FLD_FIRST,Sid::Field::KIND_STRING, MsgvideoVideoCommandResponse::END,0} } },
                /*** MsgvmVoicemailStartRecordingRequest */
                /*508*/ { { {&d24field_equals_default,&d24set_field_to_default,0,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgvmVoicemailStartRecordingRequest::END,7} } },
                /*** MsgvmVoicemailStopRecordingRequest */
                /*509*/ { { {&d24field_equals_default,&d24set_field_to_default,0,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgvmVoicemailStopRecordingRequest::END,7} } },
                /*** MsgvmVoicemailStartPlaybackRequest */
                /*510*/ { { {&d24field_equals_default,&d24set_field_to_default,0,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgvmVoicemailStartPlaybackRequest::END,7} } },
                /*** MsgvmVoicemailStopPlaybackRequest */
                /*511*/ { { {&d24field_equals_default,&d24set_field_to_default,0,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgvmVoicemailStopPlaybackRequest::END,7} } },
                /*** MsgvmVoicemailDeleteRequest */
                /*512*/ { { {&d24field_equals_default,&d24set_field_to_default,0,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgvmVoicemailDeleteRequest::END,7} } },
                /*** MsgvmVoicemailCancelRequest */
                /*513*/ { { {&d24field_equals_default,&d24set_field_to_default,0,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgvmVoicemailCancelRequest::END,7} } },
                /*** MsgvmVoicemailCheckPermissionRequest */
                /*514*/ { { {&d24field_equals_default,&d24set_field_to_default,0,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgvmVoicemailCheckPermissionRequest::END,7} } },
                /*** MsgvmVoicemailCheckPermissionResponse */
                /*515*/ { { {&d3field_equals_default,&d3set_field_to_default,1,Sid::Field::FLD_FIRST,Sid::Field::KIND_BOOLEAN, MsgvmVoicemailCheckPermissionResponse::END,0} } },
                /*** MsgvmVoicemail */
                /*516*/ { { {&d9field_equals_default,&d9set_field_to_default,100,Sid::Field::FLD_FIRST,Sid::Field::KIND_ENUM, MsgvmVoicemail::END,0} } },
                /*517*/ { { {&d1field_equals_default,&d1set_field_to_default,101,0,Sid::Field::KIND_STRING, (unsigned short) (size_t) &reinterpret_cast<MsgvmVoicemail*>(base_address)->partner_handle,0} } },
                /*518*/ { { {&d1field_equals_default,&d1set_field_to_default,102,0,Sid::Field::KIND_STRING, (unsigned short) (size_t) &reinterpret_cast<MsgvmVoicemail*>(base_address)->partner_dispname,0} } },
                /*519*/ { { {&d9field_equals_default,&d9set_field_to_default,103,0,Sid::Field::KIND_ENUM, (unsigned short) (size_t) &reinterpret_cast<MsgvmVoicemail*>(base_address)->status,0} } },
                /*520*/ { { {&d9field_equals_default,&d9set_field_to_default,104,0,Sid::Field::KIND_ENUM, (unsigned short) (size_t) &reinterpret_cast<MsgvmVoicemail*>(base_address)->failurereason,0} } },
                /*521*/ { { {&d1field_equals_default,&d1set_field_to_default,105,0,Sid::Field::KIND_STRING, (unsigned short) (size_t) &reinterpret_cast<MsgvmVoicemail*>(base_address)->subject,0} } },
                /*522*/ { { {&d8field_equals_default,&d8set_field_to_default,106,0,Sid::Field::KIND_UINT, (unsigned short) (size_t) &reinterpret_cast<MsgvmVoicemail*>(base_address)->timestamp,0} } },
                /*523*/ { { {&d8field_equals_default,&d8set_field_to_default,107,0,Sid::Field::KIND_UINT, (unsigned short) (size_t) &reinterpret_cast<MsgvmVoicemail*>(base_address)->duration,0} } },
                /*524*/ { { {&d8field_equals_default,&d8set_field_to_default,108,0,Sid::Field::KIND_UINT, (unsigned short) (size_t) &reinterpret_cast<MsgvmVoicemail*>(base_address)->allowed_duration,0} } },
                /*525*/ { { {&d8field_equals_default,&d8set_field_to_default,109,0,Sid::Field::KIND_UINT, (unsigned short) (size_t) &reinterpret_cast<MsgvmVoicemail*>(base_address)->playback_progress,0} } },
                /*526*/ { { {&d5field_equals_default,&d5set_field_to_default,830,0,Sid::Field::KIND_OBJECTID, (unsigned short) (size_t) &reinterpret_cast<MsgvmVoicemail*>(base_address)->convo_id,18} } },
                /*527*/ { { {&d11field_equals_default,&d11set_field_to_default,831,0,Sid::Field::KIND_BINARY, (unsigned short) (size_t) &reinterpret_cast<MsgvmVoicemail*>(base_address)->chatmsg_guid,0} } },
                /*** MsgvmGetGreetingRequest */
                /*528*/ { { {&d1field_equals_default,&d1set_field_to_default,1,Sid::Field::FLD_FIRST,Sid::Field::KIND_STRING, MsgvmGetGreetingRequest::END,0} } },
                /*** MsgvmGetGreetingResponse */
                /*529*/ { { {&d24field_equals_default,&d24set_field_to_default,1,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgvmGetGreetingResponse::END,7} } },
                /*** MsgaudioPlayStartRequest */
                /*530*/ { { {&d8field_equals_default,&d8set_field_to_default,1,Sid::Field::FLD_FIRST,Sid::Field::KIND_UINT, MsgaudioPlayStartRequest::END,0} } },
                /*531*/ { { {&d11field_equals_default,&d11set_field_to_default,2,0,Sid::Field::KIND_BINARY, (unsigned short) (size_t) &reinterpret_cast<MsgaudioPlayStartRequest*>(base_address)->sound,0} } },
                /*532*/ { { {&d3field_equals_default,&d3set_field_to_default,3,0,Sid::Field::KIND_BOOLEAN, (unsigned short) (size_t) &reinterpret_cast<MsgaudioPlayStartRequest*>(base_address)->loop,0} } },
                /*533*/ { { {&d12field_equals_default,&d12set_field_to_default,4,0,Sid::Field::KIND_BOOLEAN, (unsigned short) (size_t) &reinterpret_cast<MsgaudioPlayStartRequest*>(base_address)->useCallOutDevice,0} } },
                /*** MsgaudioPlayStartFromFileRequest */
                /*534*/ { { {&d8field_equals_default,&d8set_field_to_default,1,Sid::Field::FLD_FIRST,Sid::Field::KIND_UINT, MsgaudioPlayStartFromFileRequest::END,0} } },
                /*535*/ { { {&d23field_equals_default,&d23set_field_to_default,2,0,Sid::Field::KIND_FILENAME, (unsigned short) (size_t) &reinterpret_cast<MsgaudioPlayStartFromFileRequest*>(base_address)->datafile,0} } },
                /*536*/ { { {&d3field_equals_default,&d3set_field_to_default,3,0,Sid::Field::KIND_BOOLEAN, (unsigned short) (size_t) &reinterpret_cast<MsgaudioPlayStartFromFileRequest*>(base_address)->loop,0} } },
                /*537*/ { { {&d12field_equals_default,&d12set_field_to_default,4,0,Sid::Field::KIND_BOOLEAN, (unsigned short) (size_t) &reinterpret_cast<MsgaudioPlayStartFromFileRequest*>(base_address)->useCallOutDevice,0} } },
                /*** MsgaudioPlayStartFromFileResponse */
                /*538*/ { { {&d9field_equals_default,&d9set_field_to_default,1,Sid::Field::FLD_FIRST,Sid::Field::KIND_ENUM, MsgaudioPlayStartFromFileResponse::END,0} } },
                /*** MsgaudioPlayStopRequest */
                /*539*/ { { {&d8field_equals_default,&d8set_field_to_default,1,Sid::Field::FLD_FIRST,Sid::Field::KIND_UINT, MsgaudioPlayStopRequest::END,0} } },                /*** MsgaudioStartRecordingTestRequest */
                /*540*/ { { {&d12field_equals_default,&d12set_field_to_default,1,Sid::Field::FLD_FIRST,Sid::Field::KIND_BOOLEAN, MsgaudioStartRecordingTestRequest::END,0} } },
                /*** MsgaudioGetAvailableOutputDevicesResponse */
                /*541*/ { { {&d19field_equals_default,&d19set_field_to_default,1,Sid::Field::FLD_FIRST|Sid::Field::FLD_LIST,Sid::Field::KIND_STRING, MsgaudioGetAvailableOutputDevicesResponse::END,0} } },
                { { { reinterpret_cast<bool(*)(const void*)>(&d19append),reinterpret_cast<void(*)(void*)>(&d19iterate),0,0,0,0,0}}},
                /*543*/ { { {&d19field_equals_default,&d19set_field_to_default,2,Sid::Field::FLD_LIST,Sid::Field::KIND_STRING, (unsigned short) (size_t) &reinterpret_cast<MsgaudioGetAvailableOutputDevicesResponse*>(base_address)->nameList,0} } },
                { { { reinterpret_cast<bool(*)(const void*)>(&d19append),reinterpret_cast<void(*)(void*)>(&d19iterate),0,0,0,0,0}}},
                /*545*/ { { {&d19field_equals_default,&d19set_field_to_default,3,Sid::Field::FLD_LIST,Sid::Field::KIND_STRING, (unsigned short) (size_t) &reinterpret_cast<MsgaudioGetAvailableOutputDevicesResponse*>(base_address)->productIdList,0} } },
                { { { reinterpret_cast<bool(*)(const void*)>(&d19append),reinterpret_cast<void(*)(void*)>(&d19iterate),0,0,0,0,0}}},
                /*** MsgaudioGetAvailableRecordingDevicesResponse */
                /*547*/ { { {&d19field_equals_default,&d19set_field_to_default,1,Sid::Field::FLD_FIRST|Sid::Field::FLD_LIST,Sid::Field::KIND_STRING, MsgaudioGetAvailableRecordingDevicesResponse::END,0} } },
                { { { reinterpret_cast<bool(*)(const void*)>(&d19append),reinterpret_cast<void(*)(void*)>(&d19iterate),0,0,0,0,0}}},
                /*549*/ { { {&d19field_equals_default,&d19set_field_to_default,2,Sid::Field::FLD_LIST,Sid::Field::KIND_STRING, (unsigned short) (size_t) &reinterpret_cast<MsgaudioGetAvailableRecordingDevicesResponse*>(base_address)->nameList,0} } },
                { { { reinterpret_cast<bool(*)(const void*)>(&d19append),reinterpret_cast<void(*)(void*)>(&d19iterate),0,0,0,0,0}}},
                /*551*/ { { {&d19field_equals_default,&d19set_field_to_default,3,Sid::Field::FLD_LIST,Sid::Field::KIND_STRING, (unsigned short) (size_t) &reinterpret_cast<MsgaudioGetAvailableRecordingDevicesResponse*>(base_address)->productIdList,0} } },
                { { { reinterpret_cast<bool(*)(const void*)>(&d19append),reinterpret_cast<void(*)(void*)>(&d19iterate),0,0,0,0,0}}},
                /*** MsgaudioSelectSoundDevicesRequest */
                /*553*/ { { {&d1field_equals_default,&d1set_field_to_default,1,Sid::Field::FLD_FIRST,Sid::Field::KIND_STRING, MsgaudioSelectSoundDevicesRequest::END,0} } },
                /*554*/ { { {&d1field_equals_default,&d1set_field_to_default,2,0,Sid::Field::KIND_STRING, (unsigned short) (size_t) &reinterpret_cast<MsgaudioSelectSoundDevicesRequest*>(base_address)->callOutDevice,0} } },
                /*555*/ { { {&d1field_equals_default,&d1set_field_to_default,3,0,Sid::Field::KIND_STRING, (unsigned short) (size_t) &reinterpret_cast<MsgaudioSelectSoundDevicesRequest*>(base_address)->waveOutDevice,0} } },
                /*** MsgaudioGetAudioDeviceCapabilitiesRequest */
                /*556*/ { { {&d1field_equals_default,&d1set_field_to_default,1,Sid::Field::FLD_FIRST,Sid::Field::KIND_STRING, MsgaudioGetAudioDeviceCapabilitiesRequest::END,0} } },
                /*** MsgaudioGetAudioDeviceCapabilitiesResponse */
                /*557*/ { { {&d1field_equals_default,&d1set_field_to_default,1,Sid::Field::FLD_FIRST,Sid::Field::KIND_STRING, MsgaudioGetAudioDeviceCapabilitiesResponse::END,0} } },
                /*558*/ { { {&d8field_equals_default,&d8set_field_to_default,2,0,Sid::Field::KIND_UINT, (unsigned short) (size_t) &reinterpret_cast<MsgaudioGetAudioDeviceCapabilitiesResponse*>(base_address)->capabilities,0} } },
                /*** MsgaudioGetNrgLevelsResponse */
                /*559*/ { { {&d8field_equals_default,&d8set_field_to_default,1,Sid::Field::FLD_FIRST,Sid::Field::KIND_UINT, MsgaudioGetNrgLevelsResponse::END,0} } },
                /*560*/ { { {&d8field_equals_default,&d8set_field_to_default,2,0,Sid::Field::KIND_UINT, (unsigned short) (size_t) &reinterpret_cast<MsgaudioGetNrgLevelsResponse*>(base_address)->speakerLevel,0} } },
                /*** MsgaudioVoiceCommandRequest */
                /*561*/ { { {&d1field_equals_default,&d1set_field_to_default,1,Sid::Field::FLD_FIRST,Sid::Field::KIND_STRING, MsgaudioVoiceCommandRequest::END,0} } },
                /*** MsgaudioVoiceCommandResponse */
                /*562*/ { { {&d1field_equals_default,&d1set_field_to_default,1,Sid::Field::FLD_FIRST,Sid::Field::KIND_STRING, MsgaudioVoiceCommandResponse::END,0} } },
                /*** MsgaudioGetSpeakerVolumeResponse */
                /*563*/ { { {&d8field_equals_default,&d8set_field_to_default,1,Sid::Field::FLD_FIRST,Sid::Field::KIND_UINT, MsgaudioGetSpeakerVolumeResponse::END,0} } },
                /*** MsgaudioSetSpeakerVolumeRequest */
                /*564*/ { { {&d8field_equals_default,&d8set_field_to_default,1,Sid::Field::FLD_FIRST,Sid::Field::KIND_UINT, MsgaudioSetSpeakerVolumeRequest::END,0} } },
                /*** MsgaudioGetMicVolumeResponse */
                /*565*/ { { {&d8field_equals_default,&d8set_field_to_default,1,Sid::Field::FLD_FIRST,Sid::Field::KIND_UINT, MsgaudioGetMicVolumeResponse::END,0} } },
                /*** MsgaudioSetMicVolumeRequest */
                /*566*/ { { {&d8field_equals_default,&d8set_field_to_default,1,Sid::Field::FLD_FIRST,Sid::Field::KIND_UINT, MsgaudioSetMicVolumeRequest::END,0} } },
                /*** MsgaudioIsSpeakerMutedResponse */
                /*567*/ { { {&d3field_equals_default,&d3set_field_to_default,1,Sid::Field::FLD_FIRST,Sid::Field::KIND_BOOLEAN, MsgaudioIsSpeakerMutedResponse::END,0} } },
                /*** MsgaudioIsMicrophoneMutedResponse */
                /*568*/ { { {&d3field_equals_default,&d3set_field_to_default,1,Sid::Field::FLD_FIRST,Sid::Field::KIND_BOOLEAN, MsgaudioIsMicrophoneMutedResponse::END,0} } },
                /*** MsgaudioMuteSpeakersRequest */
                /*569*/ { { {&d3field_equals_default,&d3set_field_to_default,1,Sid::Field::FLD_FIRST,Sid::Field::KIND_BOOLEAN, MsgaudioMuteSpeakersRequest::END,0} } },
                /*** MsgaudioMuteMicrophoneRequest */
                /*570*/ { { {&d3field_equals_default,&d3set_field_to_default,1,Sid::Field::FLD_FIRST,Sid::Field::KIND_BOOLEAN, MsgaudioMuteMicrophoneRequest::END,0} } },
                /*** MsgbwmSetOperatingMediaRequest */
                /*571*/ { { {&d9field_equals_default,&d9set_field_to_default,1,Sid::Field::FLD_FIRST,Sid::Field::KIND_ENUM, MsgbwmSetOperatingMediaRequest::END,0} } },
                /*572*/ { { {&d8field_equals_default,&d8set_field_to_default,2,0,Sid::Field::KIND_UINT, (unsigned short) (size_t) &reinterpret_cast<MsgbwmSetOperatingMediaRequest*>(base_address)->maxUplinkBps,0} } },
                /*573*/ { { {&d8field_equals_default,&d8set_field_to_default,3,0,Sid::Field::KIND_UINT, (unsigned short) (size_t) &reinterpret_cast<MsgbwmSetOperatingMediaRequest*>(base_address)->maxDownlinkBps,0} } },
                /*** MsgsmsSmsGetTargetStatusRequest */
                /*574*/ { { {&d25field_equals_default,&d25set_field_to_default,0,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgsmsSmsGetTargetStatusRequest::END,12} } },
                /*575*/ { { {&d1field_equals_default,&d1set_field_to_default,1,0,Sid::Field::KIND_STRING, (unsigned short) (size_t) &reinterpret_cast<MsgsmsSmsGetTargetStatusRequest*>(base_address)->target,0} } },
                /*** MsgsmsSmsGetTargetStatusResponse */
                /*576*/ { { {&d9field_equals_default,&d9set_field_to_default,1,Sid::Field::FLD_FIRST,Sid::Field::KIND_ENUM, MsgsmsSmsGetTargetStatusResponse::END,0} } },
                /*** MsgsmsSmsGetTargetPriceRequest */
                /*577*/ { { {&d25field_equals_default,&d25set_field_to_default,0,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgsmsSmsGetTargetPriceRequest::END,12} } },                /*578*/ { { {&d1field_equals_default,&d1set_field_to_default,1,0,Sid::Field::KIND_STRING, (unsigned short) (size_t) &reinterpret_cast<MsgsmsSmsGetTargetPriceRequest*>(base_address)->target,0} } },
                /*** MsgsmsSmsGetTargetPriceResponse */
                /*579*/ { { {&d8field_equals_default,&d8set_field_to_default,1,Sid::Field::FLD_FIRST,Sid::Field::KIND_UINT, MsgsmsSmsGetTargetPriceResponse::END,0} } },
                /*** MsgsmsSmsSetTargetsRequest */
                /*580*/ { { {&d25field_equals_default,&d25set_field_to_default,0,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgsmsSmsSetTargetsRequest::END,12} } },
                /*581*/ { { {&d19field_equals_default,&d19set_field_to_default,1,Sid::Field::FLD_LIST,Sid::Field::KIND_STRING, (unsigned short) (size_t) &reinterpret_cast<MsgsmsSmsSetTargetsRequest*>(base_address)->numbers,0} } },
                { { { reinterpret_cast<bool(*)(const void*)>(&d19append),reinterpret_cast<void(*)(void*)>(&d19iterate),0,0,0,0,0}}},
                /*** MsgsmsSmsSetTargetsResponse */
                /*583*/ { { {&d3field_equals_default,&d3set_field_to_default,1,Sid::Field::FLD_FIRST,Sid::Field::KIND_BOOLEAN, MsgsmsSmsSetTargetsResponse::END,0} } },
                /*** MsgsmsSmsSetBodyRequest */
                /*584*/ { { {&d25field_equals_default,&d25set_field_to_default,0,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgsmsSmsSetBodyRequest::END,12} } },
                /*585*/ { { {&d1field_equals_default,&d1set_field_to_default,1,0,Sid::Field::KIND_STRING, (unsigned short) (size_t) &reinterpret_cast<MsgsmsSmsSetBodyRequest*>(base_address)->text,0} } },
                /*** MsgsmsSmsSetBodyResponse */
                /*586*/ { { {&d9field_equals_default,&d9set_field_to_default,1,Sid::Field::FLD_FIRST,Sid::Field::KIND_ENUM, MsgsmsSmsSetBodyResponse::END,0} } },
                /*587*/ { { {&d19field_equals_default,&d19set_field_to_default,2,Sid::Field::FLD_LIST,Sid::Field::KIND_STRING, (unsigned short) (size_t) &reinterpret_cast<MsgsmsSmsSetBodyResponse*>(base_address)->chunks,0} } },
                { { { reinterpret_cast<bool(*)(const void*)>(&d19append),reinterpret_cast<void(*)(void*)>(&d19iterate),0,0,0,0,0}}},
                /*589*/ { { {&d8field_equals_default,&d8set_field_to_default,3,0,Sid::Field::KIND_UINT, (unsigned short) (size_t) &reinterpret_cast<MsgsmsSmsSetBodyResponse*>(base_address)->charsUntilNextChunk,0} } },
                /*** MsgsmsSmsGetBodyChunksRequest */
                /*590*/ { { {&d25field_equals_default,&d25set_field_to_default,0,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgsmsSmsGetBodyChunksRequest::END,12} } },
                /*** MsgsmsSmsGetBodyChunksResponse */
                /*591*/ { { {&d19field_equals_default,&d19set_field_to_default,1,Sid::Field::FLD_FIRST|Sid::Field::FLD_LIST,Sid::Field::KIND_STRING, MsgsmsSmsGetBodyChunksResponse::END,0} } },
                { { { reinterpret_cast<bool(*)(const void*)>(&d19append),reinterpret_cast<void(*)(void*)>(&d19iterate),0,0,0,0,0}}},
                /*593*/ { { {&d8field_equals_default,&d8set_field_to_default,2,0,Sid::Field::KIND_UINT, (unsigned short) (size_t) &reinterpret_cast<MsgsmsSmsGetBodyChunksResponse*>(base_address)->charsUntilNextChunk,0} } },
                /*** MsgsmsSms */
                /*594*/ { { {&d3field_equals_default,&d3set_field_to_default,48,Sid::Field::FLD_FIRST,Sid::Field::KIND_BOOLEAN, MsgsmsSms::END,0} } },
                /*595*/ { { {&d8field_equals_default,&d8set_field_to_default,49,0,Sid::Field::KIND_UINT, (unsigned short) (size_t) &reinterpret_cast<MsgsmsSms*>(base_address)->price_precision,0} } },
                /*596*/ { { {&d9field_equals_default,&d9set_field_to_default,190,0,Sid::Field::KIND_ENUM, (unsigned short) (size_t) &reinterpret_cast<MsgsmsSms*>(base_address)->type,0} } },
                /*597*/ { { {&d9field_equals_default,&d9set_field_to_default,191,0,Sid::Field::KIND_ENUM, (unsigned short) (size_t) &reinterpret_cast<MsgsmsSms*>(base_address)->status,0} } },
                /*598*/ { { {&d9field_equals_default,&d9set_field_to_default,192,0,Sid::Field::KIND_ENUM, (unsigned short) (size_t) &reinterpret_cast<MsgsmsSms*>(base_address)->failurereason,0} } },
                /*599*/ { { {&d8field_equals_default,&d8set_field_to_default,193,0,Sid::Field::KIND_UINT, (unsigned short) (size_t) &reinterpret_cast<MsgsmsSms*>(base_address)->price,0} } },
                /*600*/ { { {&d1field_equals_default,&d1set_field_to_default,194,0,Sid::Field::KIND_STRING, (unsigned short) (size_t) &reinterpret_cast<MsgsmsSms*>(base_address)->price_currency,0} } },
                /*601*/ { { {&d1field_equals_default,&d1set_field_to_default,195,0,Sid::Field::KIND_STRING, (unsigned short) (size_t) &reinterpret_cast<MsgsmsSms*>(base_address)->target_numbers,0} } },
                /*602*/ { { {&d11field_equals_default,&d11set_field_to_default,196,0,Sid::Field::KIND_BINARY, (unsigned short) (size_t) &reinterpret_cast<MsgsmsSms*>(base_address)->target_statuses,0} } },
                /*603*/ { { {&d1field_equals_default,&d1set_field_to_default,197,0,Sid::Field::KIND_STRING, (unsigned short) (size_t) &reinterpret_cast<MsgsmsSms*>(base_address)->body,0} } },
                /*604*/ { { {&d8field_equals_default,&d8set_field_to_default,198,0,Sid::Field::KIND_UINT, (unsigned short) (size_t) &reinterpret_cast<MsgsmsSms*>(base_address)->timestamp,0} } },
                /*605*/ { { {&d1field_equals_default,&d1set_field_to_default,199,0,Sid::Field::KIND_STRING, (unsigned short) (size_t) &reinterpret_cast<MsgsmsSms*>(base_address)->reply_to_number,0} } },
                /*606*/ { { {&d21field_equals_default,&d21set_field_to_default,840,0,Sid::Field::KIND_OBJECTID, (unsigned short) (size_t) &reinterpret_cast<MsgsmsSms*>(base_address)->chatmsg_id,9} } },
                /*** MsgsmsRequestConfirmationCodeRequest */
                /*607*/ { { {&d9field_equals_default,&d9set_field_to_default,1,Sid::Field::FLD_FIRST,Sid::Field::KIND_ENUM, MsgsmsRequestConfirmationCodeRequest::END,0} } },
                /*608*/ { { {&d1field_equals_default,&d1set_field_to_default,2,0,Sid::Field::KIND_STRING, (unsigned short) (size_t) &reinterpret_cast<MsgsmsRequestConfirmationCodeRequest*>(base_address)->number,0} } },
                /*** MsgsmsRequestConfirmationCodeResponse */
                /*609*/ { { {&d25field_equals_default,&d25set_field_to_default,1,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgsmsRequestConfirmationCodeResponse::END,12} } },
                /*** MsgsmsSubmitConfirmationCodeRequest */
                /*610*/ { { {&d1field_equals_default,&d1set_field_to_default,1,Sid::Field::FLD_FIRST,Sid::Field::KIND_STRING, MsgsmsSubmitConfirmationCodeRequest::END,0} } },
                /*611*/ { { {&d1field_equals_default,&d1set_field_to_default,2,0,Sid::Field::KIND_STRING, (unsigned short) (size_t) &reinterpret_cast<MsgsmsSubmitConfirmationCodeRequest*>(base_address)->code,0} } },
                /*** MsgsmsSubmitConfirmationCodeResponse */
                /*612*/ { { {&d25field_equals_default,&d25set_field_to_default,1,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgsmsSubmitConfirmationCodeResponse::END,12} } },
                /*** MsgsmsCreateOutgoingSmsResponse */
                /*613*/ { { {&d25field_equals_default,&d25set_field_to_default,1,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgsmsCreateOutgoingSmsResponse::END,12} } },
                /*** MsgftTransferAcceptRequest */
                /*614*/ { { {&d29field_equals_default,&d29set_field_to_default,0,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgftTransferAcceptRequest::END,6} } },
                /*615*/ { { {&d23field_equals_default,&d23set_field_to_default,1,0,Sid::Field::KIND_FILENAME, (unsigned short) (size_t) &reinterpret_cast<MsgftTransferAcceptRequest*>(base_address)->filenameWithPath,0} } },
                /*** MsgftTransferAcceptResponse */
                /*616*/ { { {&d3field_equals_default,&d3set_field_to_default,1,Sid::Field::FLD_FIRST,Sid::Field::KIND_BOOLEAN, MsgftTransferAcceptResponse::END,0} } },
                /*** MsgftTransferPauseRequest */
                /*617*/ { { {&d29field_equals_default,&d29set_field_to_default,0,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgftTransferPauseRequest::END,6} } },                /*** MsgftTransferResumeRequest */
                /*618*/ { { {&d29field_equals_default,&d29set_field_to_default,0,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgftTransferResumeRequest::END,6} } },
                /*** MsgftTransferCancelRequest */
                /*619*/ { { {&d29field_equals_default,&d29set_field_to_default,0,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgftTransferCancelRequest::END,6} } },
                /*** MsgftTransfer */
                /*620*/ { { {&d9field_equals_default,&d9set_field_to_default,80,Sid::Field::FLD_FIRST,Sid::Field::KIND_ENUM, MsgftTransfer::END,0} } },
                /*621*/ { { {&d1field_equals_default,&d1set_field_to_default,81,0,Sid::Field::KIND_STRING, (unsigned short) (size_t) &reinterpret_cast<MsgftTransfer*>(base_address)->partner_handle,0} } },
                /*622*/ { { {&d1field_equals_default,&d1set_field_to_default,82,0,Sid::Field::KIND_STRING, (unsigned short) (size_t) &reinterpret_cast<MsgftTransfer*>(base_address)->partner_dispname,0} } },
                /*623*/ { { {&d9field_equals_default,&d9set_field_to_default,83,0,Sid::Field::KIND_ENUM, (unsigned short) (size_t) &reinterpret_cast<MsgftTransfer*>(base_address)->status,0} } },
                /*624*/ { { {&d9field_equals_default,&d9set_field_to_default,84,0,Sid::Field::KIND_ENUM, (unsigned short) (size_t) &reinterpret_cast<MsgftTransfer*>(base_address)->failurereason,0} } },
                /*625*/ { { {&d8field_equals_default,&d8set_field_to_default,85,0,Sid::Field::KIND_UINT, (unsigned short) (size_t) &reinterpret_cast<MsgftTransfer*>(base_address)->starttime,0} } },
                /*626*/ { { {&d8field_equals_default,&d8set_field_to_default,86,0,Sid::Field::KIND_UINT, (unsigned short) (size_t) &reinterpret_cast<MsgftTransfer*>(base_address)->finishtime,0} } },
                /*627*/ { { {&d1field_equals_default,&d1set_field_to_default,87,0,Sid::Field::KIND_STRING, (unsigned short) (size_t) &reinterpret_cast<MsgftTransfer*>(base_address)->filepath,0} } },
                /*628*/ { { {&d1field_equals_default,&d1set_field_to_default,88,0,Sid::Field::KIND_STRING, (unsigned short) (size_t) &reinterpret_cast<MsgftTransfer*>(base_address)->filename,0} } },
                /*629*/ { { {&d1field_equals_default,&d1set_field_to_default,89,0,Sid::Field::KIND_STRING, (unsigned short) (size_t) &reinterpret_cast<MsgftTransfer*>(base_address)->filesize,0} } },
                /*630*/ { { {&d1field_equals_default,&d1set_field_to_default,90,0,Sid::Field::KIND_STRING, (unsigned short) (size_t) &reinterpret_cast<MsgftTransfer*>(base_address)->bytestransferred,0} } },
                /*631*/ { { {&d8field_equals_default,&d8set_field_to_default,91,0,Sid::Field::KIND_UINT, (unsigned short) (size_t) &reinterpret_cast<MsgftTransfer*>(base_address)->bytespersecond,0} } },
                /*632*/ { { {&d11field_equals_default,&d11set_field_to_default,92,0,Sid::Field::KIND_BINARY, (unsigned short) (size_t) &reinterpret_cast<MsgftTransfer*>(base_address)->chatmsg_guid,0} } },
                /*633*/ { { {&d8field_equals_default,&d8set_field_to_default,93,0,Sid::Field::KIND_UINT, (unsigned short) (size_t) &reinterpret_cast<MsgftTransfer*>(base_address)->chatmsg_index,0} } },
                /*634*/ { { {&d5field_equals_default,&d5set_field_to_default,98,0,Sid::Field::KIND_OBJECTID, (unsigned short) (size_t) &reinterpret_cast<MsgftTransfer*>(base_address)->convo_id,18} } },
                /*** MsgaccountAccountGetStatusWithProgressRequest */
                /*635*/ { { {&d30field_equals_default,&d30set_field_to_default,0,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgaccountAccountGetStatusWithProgressRequest::END,5} } },
                /*** MsgaccountAccountGetStatusWithProgressResponse */
                /*636*/ { { {&d9field_equals_default,&d9set_field_to_default,1,Sid::Field::FLD_FIRST,Sid::Field::KIND_ENUM, MsgaccountAccountGetStatusWithProgressResponse::END,0} } },
                /*637*/ { { {&d8field_equals_default,&d8set_field_to_default,2,0,Sid::Field::KIND_UINT, (unsigned short) (size_t) &reinterpret_cast<MsgaccountAccountGetStatusWithProgressResponse*>(base_address)->progress,0} } },
                /*** MsgaccountAccountLoginRequest */
                /*638*/ { { {&d30field_equals_default,&d30set_field_to_default,0,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgaccountAccountLoginRequest::END,5} } },
                /*639*/ { { {&d9field_equals_default,&d9set_field_to_default,1,0,Sid::Field::KIND_ENUM, (unsigned short) (size_t) &reinterpret_cast<MsgaccountAccountLoginRequest*>(base_address)->setAvailabilityTo,0} } },
                /*** MsgaccountAccountLoginWithPasswordRequest */
                /*640*/ { { {&d30field_equals_default,&d30set_field_to_default,0,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgaccountAccountLoginWithPasswordRequest::END,5} } },
                /*641*/ { { {&d1field_equals_default,&d1set_field_to_default,1,0,Sid::Field::KIND_STRING, (unsigned short) (size_t) &reinterpret_cast<MsgaccountAccountLoginWithPasswordRequest*>(base_address)->password,0} } },
                /*642*/ { { {&d12field_equals_default,&d12set_field_to_default,2,0,Sid::Field::KIND_BOOLEAN, (unsigned short) (size_t) &reinterpret_cast<MsgaccountAccountLoginWithPasswordRequest*>(base_address)->savePwd,0} } },
                /*643*/ { { {&d13field_equals_default,&d13set_field_to_default,3,0,Sid::Field::KIND_BOOLEAN, (unsigned short) (size_t) &reinterpret_cast<MsgaccountAccountLoginWithPasswordRequest*>(base_address)->saveDataLocally,0} } },
                /*** MsgaccountAccountRegisterRequest */
                /*644*/ { { {&d30field_equals_default,&d30set_field_to_default,0,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgaccountAccountRegisterRequest::END,5} } },
                /*645*/ { { {&d1field_equals_default,&d1set_field_to_default,1,0,Sid::Field::KIND_STRING, (unsigned short) (size_t) &reinterpret_cast<MsgaccountAccountRegisterRequest*>(base_address)->password,0} } },
                /*646*/ { { {&d12field_equals_default,&d12set_field_to_default,2,0,Sid::Field::KIND_BOOLEAN, (unsigned short) (size_t) &reinterpret_cast<MsgaccountAccountRegisterRequest*>(base_address)->savePwd,0} } },
                /*647*/ { { {&d13field_equals_default,&d13set_field_to_default,3,0,Sid::Field::KIND_BOOLEAN, (unsigned short) (size_t) &reinterpret_cast<MsgaccountAccountRegisterRequest*>(base_address)->saveDataLocally,0} } },
                /*648*/ { { {&d1field_equals_default,&d1set_field_to_default,4,0,Sid::Field::KIND_STRING, (unsigned short) (size_t) &reinterpret_cast<MsgaccountAccountRegisterRequest*>(base_address)->email,0} } },
                /*649*/ { { {&d12field_equals_default,&d12set_field_to_default,5,0,Sid::Field::KIND_BOOLEAN, (unsigned short) (size_t) &reinterpret_cast<MsgaccountAccountRegisterRequest*>(base_address)->allowSpam,0} } },
                /*** MsgaccountAccountLogoutRequest */
                /*650*/ { { {&d30field_equals_default,&d30set_field_to_default,0,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgaccountAccountLogoutRequest::END,5} } },
                /*651*/ { { {&d12field_equals_default,&d12set_field_to_default,1,0,Sid::Field::KIND_BOOLEAN, (unsigned short) (size_t) &reinterpret_cast<MsgaccountAccountLogoutRequest*>(base_address)->clearSavedPwd,0} } },
                /*** MsgaccountAccountChangePasswordRequest */
                /*652*/ { { {&d30field_equals_default,&d30set_field_to_default,0,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgaccountAccountChangePasswordRequest::END,5} } },
                /*653*/ { { {&d1field_equals_default,&d1set_field_to_default,1,0,Sid::Field::KIND_STRING, (unsigned short) (size_t) &reinterpret_cast<MsgaccountAccountChangePasswordRequest*>(base_address)->oldPassword,0} } },
                /*654*/ { { {&d1field_equals_default,&d1set_field_to_default,2,0,Sid::Field::KIND_STRING, (unsigned short) (size_t) &reinterpret_cast<MsgaccountAccountChangePasswordRequest*>(base_address)->newPassword,0} } },
                /*655*/ { { {&d12field_equals_default,&d12set_field_to_default,3,0,Sid::Field::KIND_BOOLEAN, (unsigned short) (size_t) &reinterpret_cast<MsgaccountAccountChangePasswordRequest*>(base_address)->savePwd,0} } },                /*** MsgaccountAccountSetPasswordSavedRequest */
                /*656*/ { { {&d30field_equals_default,&d30set_field_to_default,0,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgaccountAccountSetPasswordSavedRequest::END,5} } },
                /*657*/ { { {&d3field_equals_default,&d3set_field_to_default,1,0,Sid::Field::KIND_BOOLEAN, (unsigned short) (size_t) &reinterpret_cast<MsgaccountAccountSetPasswordSavedRequest*>(base_address)->savePwd,0} } },
                /*** MsgaccountAccountSetServersideIntPropertyRequest */
                /*658*/ { { {&d30field_equals_default,&d30set_field_to_default,0,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgaccountAccountSetServersideIntPropertyRequest::END,5} } },
                /*659*/ { { {&d9field_equals_default,&d9set_field_to_default,1,0,Sid::Field::KIND_ENUM, (unsigned short) (size_t) &reinterpret_cast<MsgaccountAccountSetServersideIntPropertyRequest*>(base_address)->propKey,0} } },
                /*660*/ { { {&d8field_equals_default,&d8set_field_to_default,2,0,Sid::Field::KIND_UINT, (unsigned short) (size_t) &reinterpret_cast<MsgaccountAccountSetServersideIntPropertyRequest*>(base_address)->value,0} } },
                /*** MsgaccountAccountSetServersideStrPropertyRequest */
                /*661*/ { { {&d30field_equals_default,&d30set_field_to_default,0,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgaccountAccountSetServersideStrPropertyRequest::END,5} } },
                /*662*/ { { {&d9field_equals_default,&d9set_field_to_default,1,0,Sid::Field::KIND_ENUM, (unsigned short) (size_t) &reinterpret_cast<MsgaccountAccountSetServersideStrPropertyRequest*>(base_address)->propKey,0} } },
                /*663*/ { { {&d1field_equals_default,&d1set_field_to_default,2,0,Sid::Field::KIND_STRING, (unsigned short) (size_t) &reinterpret_cast<MsgaccountAccountSetServersideStrPropertyRequest*>(base_address)->value,0} } },
                /*** MsgaccountAccountCancelServerCommitRequest */
                /*664*/ { { {&d30field_equals_default,&d30set_field_to_default,0,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgaccountAccountCancelServerCommitRequest::END,5} } },
                /*** MsgaccountAccountSetIntPropertyRequest */
                /*665*/ { { {&d30field_equals_default,&d30set_field_to_default,0,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgaccountAccountSetIntPropertyRequest::END,5} } },
                /*666*/ { { {&d9field_equals_default,&d9set_field_to_default,1,0,Sid::Field::KIND_ENUM, (unsigned short) (size_t) &reinterpret_cast<MsgaccountAccountSetIntPropertyRequest*>(base_address)->propKey,0} } },
                /*667*/ { { {&d8field_equals_default,&d8set_field_to_default,2,0,Sid::Field::KIND_UINT, (unsigned short) (size_t) &reinterpret_cast<MsgaccountAccountSetIntPropertyRequest*>(base_address)->value,0} } },
                /*** MsgaccountAccountSetStrPropertyRequest */
                /*668*/ { { {&d30field_equals_default,&d30set_field_to_default,0,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgaccountAccountSetStrPropertyRequest::END,5} } },
                /*669*/ { { {&d9field_equals_default,&d9set_field_to_default,1,0,Sid::Field::KIND_ENUM, (unsigned short) (size_t) &reinterpret_cast<MsgaccountAccountSetStrPropertyRequest*>(base_address)->propKey,0} } },
                /*670*/ { { {&d1field_equals_default,&d1set_field_to_default,2,0,Sid::Field::KIND_STRING, (unsigned short) (size_t) &reinterpret_cast<MsgaccountAccountSetStrPropertyRequest*>(base_address)->value,0} } },
                /*** MsgaccountAccountSetBinPropertyRequest */
                /*671*/ { { {&d30field_equals_default,&d30set_field_to_default,0,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgaccountAccountSetBinPropertyRequest::END,5} } },
                /*672*/ { { {&d9field_equals_default,&d9set_field_to_default,1,0,Sid::Field::KIND_ENUM, (unsigned short) (size_t) &reinterpret_cast<MsgaccountAccountSetBinPropertyRequest*>(base_address)->propKey,0} } },
                /*673*/ { { {&d11field_equals_default,&d11set_field_to_default,2,0,Sid::Field::KIND_BINARY, (unsigned short) (size_t) &reinterpret_cast<MsgaccountAccountSetBinPropertyRequest*>(base_address)->value,0} } },
                /*** MsgaccountAccountSetAvailabilityRequest */
                /*674*/ { { {&d30field_equals_default,&d30set_field_to_default,0,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgaccountAccountSetAvailabilityRequest::END,5} } },
                /*675*/ { { {&d9field_equals_default,&d9set_field_to_default,1,0,Sid::Field::KIND_ENUM, (unsigned short) (size_t) &reinterpret_cast<MsgaccountAccountSetAvailabilityRequest*>(base_address)->availability,0} } },
                /*** MsgaccountAccountSetStandbyRequest */
                /*676*/ { { {&d30field_equals_default,&d30set_field_to_default,0,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgaccountAccountSetStandbyRequest::END,5} } },
                /*677*/ { { {&d3field_equals_default,&d3set_field_to_default,1,0,Sid::Field::KIND_BOOLEAN, (unsigned short) (size_t) &reinterpret_cast<MsgaccountAccountSetStandbyRequest*>(base_address)->standby,0} } },
                /*** MsgaccountAccountGetCapabilityStatusRequest */
                /*678*/ { { {&d30field_equals_default,&d30set_field_to_default,0,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgaccountAccountGetCapabilityStatusRequest::END,5} } },
                /*679*/ { { {&d9field_equals_default,&d9set_field_to_default,1,0,Sid::Field::KIND_ENUM, (unsigned short) (size_t) &reinterpret_cast<MsgaccountAccountGetCapabilityStatusRequest*>(base_address)->capability,0} } },
                /*** MsgaccountAccountGetCapabilityStatusResponse */
                /*680*/ { { {&d9field_equals_default,&d9set_field_to_default,1,Sid::Field::FLD_FIRST,Sid::Field::KIND_ENUM, MsgaccountAccountGetCapabilityStatusResponse::END,0} } },
                /*681*/ { { {&d8field_equals_default,&d8set_field_to_default,2,0,Sid::Field::KIND_UINT, (unsigned short) (size_t) &reinterpret_cast<MsgaccountAccountGetCapabilityStatusResponse*>(base_address)->expiryTimestamp,0} } },
                /*** MsgaccountAccountGetSkypenameHashRequest */
                /*682*/ { { {&d30field_equals_default,&d30set_field_to_default,0,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgaccountAccountGetSkypenameHashRequest::END,5} } },
                /*** MsgaccountAccountGetSkypenameHashResponse */
                /*683*/ { { {&d1field_equals_default,&d1set_field_to_default,1,Sid::Field::FLD_FIRST,Sid::Field::KIND_STRING, MsgaccountAccountGetSkypenameHashResponse::END,0} } },
                /*** MsgaccountAccountGetVerifiedEmailRequest */
                /*684*/ { { {&d30field_equals_default,&d30set_field_to_default,0,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgaccountAccountGetVerifiedEmailRequest::END,5} } },
                /*** MsgaccountAccountGetVerifiedEmailResponse */
                /*685*/ { { {&d1field_equals_default,&d1set_field_to_default,1,Sid::Field::FLD_FIRST,Sid::Field::KIND_STRING, MsgaccountAccountGetVerifiedEmailResponse::END,0} } },
                /*** MsgaccountAccountGetVerifiedCompanyRequest */
                /*686*/ { { {&d30field_equals_default,&d30set_field_to_default,0,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgaccountAccountGetVerifiedCompanyRequest::END,5} } },
                /*** MsgaccountAccountGetVerifiedCompanyResponse */
                /*687*/ { { {&d1field_equals_default,&d1set_field_to_default,1,Sid::Field::FLD_FIRST,Sid::Field::KIND_STRING, MsgaccountAccountGetVerifiedCompanyResponse::END,0} } },
                /*** MsgaccountAccountDeleteRequest */
                /*688*/ { { {&d30field_equals_default,&d30set_field_to_default,0,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgaccountAccountDeleteRequest::END,5} } },
                /*** MsgaccountAccount */
                /*689*/ { { {&d1field_equals_default,&d1set_field_to_default,4,Sid::Field::FLD_FIRST,Sid::Field::KIND_STRING, MsgaccountAccount::END,0} } },
                /*690*/ { { {&d1field_equals_default,&d1set_field_to_default,5,0,Sid::Field::KIND_STRING, (unsigned short) (size_t) &reinterpret_cast<MsgaccountAccount*>(base_address)->fullname,0} } },                /*691*/ { { {&d8field_equals_default,&d8set_field_to_default,7,0,Sid::Field::KIND_UINT, (unsigned short) (size_t) &reinterpret_cast<MsgaccountAccount*>(base_address)->birthday,0} } },
                /*692*/ { { {&d8field_equals_default,&d8set_field_to_default,8,0,Sid::Field::KIND_UINT, (unsigned short) (size_t) &reinterpret_cast<MsgaccountAccount*>(base_address)->gender,0} } },
                /*693*/ { { {&d1field_equals_default,&d1set_field_to_default,9,0,Sid::Field::KIND_STRING, (unsigned short) (size_t) &reinterpret_cast<MsgaccountAccount*>(base_address)->languages,0} } },
                /*694*/ { { {&d1field_equals_default,&d1set_field_to_default,10,0,Sid::Field::KIND_STRING, (unsigned short) (size_t) &reinterpret_cast<MsgaccountAccount*>(base_address)->country,0} } },
                /*695*/ { { {&d1field_equals_default,&d1set_field_to_default,11,0,Sid::Field::KIND_STRING, (unsigned short) (size_t) &reinterpret_cast<MsgaccountAccount*>(base_address)->province,0} } },
                /*696*/ { { {&d1field_equals_default,&d1set_field_to_default,12,0,Sid::Field::KIND_STRING, (unsigned short) (size_t) &reinterpret_cast<MsgaccountAccount*>(base_address)->city,0} } },
                /*697*/ { { {&d1field_equals_default,&d1set_field_to_default,13,0,Sid::Field::KIND_STRING, (unsigned short) (size_t) &reinterpret_cast<MsgaccountAccount*>(base_address)->phone_home,0} } },
                /*698*/ { { {&d1field_equals_default,&d1set_field_to_default,14,0,Sid::Field::KIND_STRING, (unsigned short) (size_t) &reinterpret_cast<MsgaccountAccount*>(base_address)->phone_office,0} } },
                /*699*/ { { {&d1field_equals_default,&d1set_field_to_default,15,0,Sid::Field::KIND_STRING, (unsigned short) (size_t) &reinterpret_cast<MsgaccountAccount*>(base_address)->phone_mobile,0} } },
                /*700*/ { { {&d1field_equals_default,&d1set_field_to_default,16,0,Sid::Field::KIND_STRING, (unsigned short) (size_t) &reinterpret_cast<MsgaccountAccount*>(base_address)->emails,0} } },
                /*701*/ { { {&d1field_equals_default,&d1set_field_to_default,17,0,Sid::Field::KIND_STRING, (unsigned short) (size_t) &reinterpret_cast<MsgaccountAccount*>(base_address)->homepage,0} } },
                /*702*/ { { {&d1field_equals_default,&d1set_field_to_default,18,0,Sid::Field::KIND_STRING, (unsigned short) (size_t) &reinterpret_cast<MsgaccountAccount*>(base_address)->about,0} } },
                /*703*/ { { {&d8field_equals_default,&d8set_field_to_default,19,0,Sid::Field::KIND_UINT, (unsigned short) (size_t) &reinterpret_cast<MsgaccountAccount*>(base_address)->profile_timestamp,0} } },
                /*704*/ { { {&d1field_equals_default,&d1set_field_to_default,26,0,Sid::Field::KIND_STRING, (unsigned short) (size_t) &reinterpret_cast<MsgaccountAccount*>(base_address)->mood_text,0} } },
                /*705*/ { { {&d8field_equals_default,&d8set_field_to_default,27,0,Sid::Field::KIND_UINT, (unsigned short) (size_t) &reinterpret_cast<MsgaccountAccount*>(base_address)->timezone,0} } },
                /*706*/ { { {&d8field_equals_default,&d8set_field_to_default,28,0,Sid::Field::KIND_UINT, (unsigned short) (size_t) &reinterpret_cast<MsgaccountAccount*>(base_address)->nrof_authed_buddies,0} } },
                /*707*/ { { {&d9field_equals_default,&d9set_field_to_default,34,0,Sid::Field::KIND_ENUM, (unsigned short) (size_t) &reinterpret_cast<MsgaccountAccount*>(base_address)->availability,0} } },
                /*708*/ { { {&d11field_equals_default,&d11set_field_to_default,37,0,Sid::Field::KIND_BINARY, (unsigned short) (size_t) &reinterpret_cast<MsgaccountAccount*>(base_address)->avatar_image,0} } },
                /*709*/ { { {&d9field_equals_default,&d9set_field_to_default,70,0,Sid::Field::KIND_ENUM, (unsigned short) (size_t) &reinterpret_cast<MsgaccountAccount*>(base_address)->status,0} } },
                /*710*/ { { {&d9field_equals_default,&d9set_field_to_default,71,0,Sid::Field::KIND_ENUM, (unsigned short) (size_t) &reinterpret_cast<MsgaccountAccount*>(base_address)->pwdchangestatus,0} } },
                /*711*/ { { {&d1field_equals_default,&d1set_field_to_default,72,0,Sid::Field::KIND_STRING, (unsigned short) (size_t) &reinterpret_cast<MsgaccountAccount*>(base_address)->suggested_skypename,0} } },
                /*712*/ { { {&d9field_equals_default,&d9set_field_to_default,73,0,Sid::Field::KIND_ENUM, (unsigned short) (size_t) &reinterpret_cast<MsgaccountAccount*>(base_address)->logoutreason,0} } },
                /*713*/ { { {&d1field_equals_default,&d1set_field_to_default,74,0,Sid::Field::KIND_STRING, (unsigned short) (size_t) &reinterpret_cast<MsgaccountAccount*>(base_address)->skypeout_balance_currency,0} } },
                /*714*/ { { {&d8field_equals_default,&d8set_field_to_default,75,0,Sid::Field::KIND_UINT, (unsigned short) (size_t) &reinterpret_cast<MsgaccountAccount*>(base_address)->skypeout_balance,0} } },
                /*715*/ { { {&d1field_equals_default,&d1set_field_to_default,76,0,Sid::Field::KIND_STRING, (unsigned short) (size_t) &reinterpret_cast<MsgaccountAccount*>(base_address)->skypein_numbers,0} } },
                /*716*/ { { {&d1field_equals_default,&d1set_field_to_default,77,0,Sid::Field::KIND_STRING, (unsigned short) (size_t) &reinterpret_cast<MsgaccountAccount*>(base_address)->offline_callforward,0} } },
                /*717*/ { { {&d9field_equals_default,&d9set_field_to_default,78,0,Sid::Field::KIND_ENUM, (unsigned short) (size_t) &reinterpret_cast<MsgaccountAccount*>(base_address)->commitstatus,0} } },
                /*718*/ { { {&d9field_equals_default,&d9set_field_to_default,79,0,Sid::Field::KIND_ENUM, (unsigned short) (size_t) &reinterpret_cast<MsgaccountAccount*>(base_address)->cblsyncstatus,0} } },
                /*719*/ { { {&d9field_equals_default,&d9set_field_to_default,160,0,Sid::Field::KIND_ENUM, (unsigned short) (size_t) &reinterpret_cast<MsgaccountAccount*>(base_address)->chat_policy,0} } },
                /*720*/ { { {&d9field_equals_default,&d9set_field_to_default,161,0,Sid::Field::KIND_ENUM, (unsigned short) (size_t) &reinterpret_cast<MsgaccountAccount*>(base_address)->skype_call_policy,0} } },
                /*721*/ { { {&d9field_equals_default,&d9set_field_to_default,162,0,Sid::Field::KIND_ENUM, (unsigned short) (size_t) &reinterpret_cast<MsgaccountAccount*>(base_address)->pstn_call_policy,0} } },
                /*722*/ { { {&d9field_equals_default,&d9set_field_to_default,163,0,Sid::Field::KIND_ENUM, (unsigned short) (size_t) &reinterpret_cast<MsgaccountAccount*>(base_address)->avatar_policy,0} } },
                /*723*/ { { {&d9field_equals_default,&d9set_field_to_default,164,0,Sid::Field::KIND_ENUM, (unsigned short) (size_t) &reinterpret_cast<MsgaccountAccount*>(base_address)->buddycount_policy,0} } },
                /*724*/ { { {&d9field_equals_default,&d9set_field_to_default,165,0,Sid::Field::KIND_ENUM, (unsigned short) (size_t) &reinterpret_cast<MsgaccountAccount*>(base_address)->timezone_policy,0} } },
                /*725*/ { { {&d9field_equals_default,&d9set_field_to_default,166,0,Sid::Field::KIND_ENUM, (unsigned short) (size_t) &reinterpret_cast<MsgaccountAccount*>(base_address)->webpresence_policy,0} } },
                /*726*/ { { {&d9field_equals_default,&d9set_field_to_default,168,0,Sid::Field::KIND_ENUM, (unsigned short) (size_t) &reinterpret_cast<MsgaccountAccount*>(base_address)->phonenumbers_policy,0} } },
                /*727*/ { { {&d9field_equals_default,&d9set_field_to_default,169,0,Sid::Field::KIND_ENUM, (unsigned short) (size_t) &reinterpret_cast<MsgaccountAccount*>(base_address)->voicemail_policy,0} } },
                /*728*/ { { {&d8field_equals_default,&d8set_field_to_default,182,0,Sid::Field::KIND_UINT, (unsigned short) (size_t) &reinterpret_cast<MsgaccountAccount*>(base_address)->avatar_timestamp,0} } },
                /*729*/ { { {&d8field_equals_default,&d8set_field_to_default,183,0,Sid::Field::KIND_UINT, (unsigned short) (size_t) &reinterpret_cast<MsgaccountAccount*>(base_address)->mood_timestamp,0} } },
                /*730*/ { { {&d1field_equals_default,&d1set_field_to_default,205,0,Sid::Field::KIND_XML, (unsigned short) (size_t) &reinterpret_cast<MsgaccountAccount*>(base_address)->rich_mood_text,0} } },                /*731*/ { { {&d1field_equals_default,&d1set_field_to_default,773,0,Sid::Field::KIND_STRING, (unsigned short) (size_t) &reinterpret_cast<MsgaccountAccount*>(base_address)->partner_optedout,0} } },
                /*732*/ { { {&d1field_equals_default,&d1set_field_to_default,800,0,Sid::Field::KIND_STRING, (unsigned short) (size_t) &reinterpret_cast<MsgaccountAccount*>(base_address)->service_provider_info,0} } },
                /*733*/ { { {&d8field_equals_default,&d8set_field_to_default,801,0,Sid::Field::KIND_UINT, (unsigned short) (size_t) &reinterpret_cast<MsgaccountAccount*>(base_address)->registration_timestamp,0} } },
                /*734*/ { { {&d8field_equals_default,&d8set_field_to_default,802,0,Sid::Field::KIND_UINT, (unsigned short) (size_t) &reinterpret_cast<MsgaccountAccount*>(base_address)->nr_of_other_instances,0} } },
                /*735*/ { { {&d8field_equals_default,&d8set_field_to_default,804,0,Sid::Field::KIND_UINT, (unsigned short) (size_t) &reinterpret_cast<MsgaccountAccount*>(base_address)->skypeout_precision,0} } },
                /*** MsgaccountGetAccountRequest */
                /*736*/ { { {&d1field_equals_default,&d1set_field_to_default,1,Sid::Field::FLD_FIRST,Sid::Field::KIND_STRING, MsgaccountGetAccountRequest::END,0} } },
                /*** MsgaccountGetAccountResponse */
                /*737*/ { { {&d30field_equals_default,&d30set_field_to_default,1,Sid::Field::FLD_FIRST,Sid::Field::KIND_OBJECTID, MsgaccountGetAccountResponse::END,5} } },
                /*** MsgaccountGetExistingAccountsResponse */
                /*738*/ { { {&d19field_equals_default,&d19set_field_to_default,1,Sid::Field::FLD_FIRST|Sid::Field::FLD_LIST,Sid::Field::KIND_STRING, MsgaccountGetExistingAccountsResponse::END,0} } },
                { { { reinterpret_cast<bool(*)(const void*)>(&d19append),reinterpret_cast<void(*)(void*)>(&d19iterate),0,0,0,0,0}}},
                /*** MsgaccountGetDefaultAccountNameResponse */
                /*740*/ { { {&d1field_equals_default,&d1set_field_to_default,1,Sid::Field::FLD_FIRST,Sid::Field::KIND_STRING, MsgaccountGetDefaultAccountNameResponse::END,0} } },
                /*** MsgaccountGetSuggestedSkypenameRequest */
                /*741*/ { { {&d1field_equals_default,&d1set_field_to_default,1,Sid::Field::FLD_FIRST,Sid::Field::KIND_STRING, MsgaccountGetSuggestedSkypenameRequest::END,0} } },
                /*** MsgaccountGetSuggestedSkypenameResponse */
                /*742*/ { { {&d1field_equals_default,&d1set_field_to_default,1,Sid::Field::FLD_FIRST,Sid::Field::KIND_STRING, MsgaccountGetSuggestedSkypenameResponse::END,0} } },
                /*** MsgaccountValidateAvatarRequest */
                /*743*/ { { {&d11field_equals_default,&d11set_field_to_default,1,Sid::Field::FLD_FIRST,Sid::Field::KIND_BINARY, MsgaccountValidateAvatarRequest::END,0} } },
                /*** MsgaccountValidateAvatarResponse */
                /*744*/ { { {&d9field_equals_default,&d9set_field_to_default,1,Sid::Field::FLD_FIRST,Sid::Field::KIND_ENUM, MsgaccountValidateAvatarResponse::END,0} } },
                /*745*/ { { {&d9field_equals_default,&d9set_field_to_default,2,0,Sid::Field::KIND_INT, (unsigned short) (size_t) &reinterpret_cast<MsgaccountValidateAvatarResponse*>(base_address)->freeBytesLeft,0} } },
                /*** MsgaccountValidateProfileStringRequest */
                /*746*/ { { {&d9field_equals_default,&d9set_field_to_default,1,Sid::Field::FLD_FIRST,Sid::Field::KIND_ENUM, MsgaccountValidateProfileStringRequest::END,0} } },
                /*747*/ { { {&d1field_equals_default,&d1set_field_to_default,2,0,Sid::Field::KIND_STRING, (unsigned short) (size_t) &reinterpret_cast<MsgaccountValidateProfileStringRequest*>(base_address)->strValue,0} } },
                /*748*/ { { {&d12field_equals_default,&d12set_field_to_default,3,0,Sid::Field::KIND_BOOLEAN, (unsigned short) (size_t) &reinterpret_cast<MsgaccountValidateProfileStringRequest*>(base_address)->forRegistration,0} } },
                /*** MsgaccountValidateProfileStringResponse */
                /*749*/ { { {&d9field_equals_default,&d9set_field_to_default,1,Sid::Field::FLD_FIRST,Sid::Field::KIND_ENUM, MsgaccountValidateProfileStringResponse::END,0} } },
                /*750*/ { { {&d9field_equals_default,&d9set_field_to_default,2,0,Sid::Field::KIND_INT, (unsigned short) (size_t) &reinterpret_cast<MsgaccountValidateProfileStringResponse*>(base_address)->freeBytesLeft,0} } },
                /*** MsgaccountValidatePasswordRequest */
                /*751*/ { { {&d1field_equals_default,&d1set_field_to_default,1,Sid::Field::FLD_FIRST,Sid::Field::KIND_STRING, MsgaccountValidatePasswordRequest::END,0} } },
                /*752*/ { { {&d1field_equals_default,&d1set_field_to_default,2,0,Sid::Field::KIND_STRING, (unsigned short) (size_t) &reinterpret_cast<MsgaccountValidatePasswordRequest*>(base_address)->password,0} } },
                /*** MsgaccountValidatePasswordResponse */
                /*753*/ { { {&d9field_equals_default,&d9set_field_to_default,1,Sid::Field::FLD_FIRST,Sid::Field::KIND_ENUM, MsgaccountValidatePasswordResponse::END,0} } },
                /*** MsgconnectionOnProxyAuthFailure */
                /*754*/ { { {&d9field_equals_default,&d9set_field_to_default,1,Sid::Field::FLD_FIRST,Sid::Field::KIND_ENUM, MsgconnectionOnProxyAuthFailure::END,0} } },
                /*** MsgconnectionGetUsedPortResponse */
                /*755*/ { { {&d8field_equals_default,&d8set_field_to_default,1,Sid::Field::FLD_FIRST,Sid::Field::KIND_UINT, MsgconnectionGetUsedPortResponse::END,0} } },
                /*** MsgsetupGetStrRequest */
                /*756*/ { { {&d1field_equals_default,&d1set_field_to_default,1,Sid::Field::FLD_FIRST,Sid::Field::KIND_STRING, MsgsetupGetStrRequest::END,0} } },
                /*** MsgsetupGetStrResponse */
                /*757*/ { { {&d1field_equals_default,&d1set_field_to_default,1,Sid::Field::FLD_FIRST,Sid::Field::KIND_STRING, MsgsetupGetStrResponse::END,0} } },
                /*** MsgsetupGetIntRequest */
                /*758*/ { { {&d1field_equals_default,&d1set_field_to_default,1,Sid::Field::FLD_FIRST,Sid::Field::KIND_STRING, MsgsetupGetIntRequest::END,0} } },
                /*** MsgsetupGetIntResponse */
                /*759*/ { { {&d9field_equals_default,&d9set_field_to_default,1,Sid::Field::FLD_FIRST,Sid::Field::KIND_INT, MsgsetupGetIntResponse::END,0} } },
                /*** MsgsetupGetBinRequest */
                /*760*/ { { {&d1field_equals_default,&d1set_field_to_default,1,Sid::Field::FLD_FIRST,Sid::Field::KIND_STRING, MsgsetupGetBinRequest::END,0} } },
                /*** MsgsetupGetBinResponse */
                /*761*/ { { {&d11field_equals_default,&d11set_field_to_default,1,Sid::Field::FLD_FIRST,Sid::Field::KIND_BINARY, MsgsetupGetBinResponse::END,0} } },
                /*** MsgsetupSetStrRequest */
                /*762*/ { { {&d1field_equals_default,&d1set_field_to_default,1,Sid::Field::FLD_FIRST,Sid::Field::KIND_STRING, MsgsetupSetStrRequest::END,0} } },
                /*763*/ { { {&d1field_equals_default,&d1set_field_to_default,2,0,Sid::Field::KIND_STRING, (unsigned short) (size_t) &reinterpret_cast<MsgsetupSetStrRequest*>(base_address)->value,0} } },
                /*** MsgsetupSetIntRequest */
                /*764*/ { { {&d1field_equals_default,&d1set_field_to_default,1,Sid::Field::FLD_FIRST,Sid::Field::KIND_STRING, MsgsetupSetIntRequest::END,0} } },
                /*765*/ { { {&d9field_equals_default,&d9set_field_to_default,2,0,Sid::Field::KIND_INT, (unsigned short) (size_t) &reinterpret_cast<MsgsetupSetIntRequest*>(base_address)->value,0} } },
                /*** MsgsetupSetBinRequest */
                /*766*/ { { {&d1field_equals_default,&d1set_field_to_default,1,Sid::Field::FLD_FIRST,Sid::Field::KIND_STRING, MsgsetupSetBinRequest::END,0} } },
                /*767*/ { { {&d11field_equals_default,&d11set_field_to_default,2,0,Sid::Field::KIND_BINARY, (unsigned short) (size_t) &reinterpret_cast<MsgsetupSetBinRequest*>(base_address)->value,0} } },
                /*** MsgsetupIsDefinedRequest */
                /*768*/ { { {&d1field_equals_default,&d1set_field_to_default,1,Sid::Field::FLD_FIRST,Sid::Field::KIND_STRING, MsgsetupIsDefinedRequest::END,0} } },                /*** MsgsetupIsDefinedResponse */
                /*769*/ { { {&d3field_equals_default,&d3set_field_to_default,1,Sid::Field::FLD_FIRST,Sid::Field::KIND_BOOLEAN, MsgsetupIsDefinedResponse::END,0} } },
                /*** MsgsetupDeleteRequest */
                /*770*/ { { {&d1field_equals_default,&d1set_field_to_default,1,Sid::Field::FLD_FIRST,Sid::Field::KIND_STRING, MsgsetupDeleteRequest::END,0} } },
                /*** MsgsetupGetSubKeysRequest */
                /*771*/ { { {&d1field_equals_default,&d1set_field_to_default,1,Sid::Field::FLD_FIRST,Sid::Field::KIND_STRING, MsgsetupGetSubKeysRequest::END,0} } },
                /*** MsgsetupGetSubKeysResponse */
                /*772*/ { { {&d19field_equals_default,&d19set_field_to_default,1,Sid::Field::FLD_FIRST|Sid::Field::FLD_LIST,Sid::Field::KIND_STRING, MsgsetupGetSubKeysResponse::END,0} } },
                { { { reinterpret_cast<bool(*)(const void*)>(&d19append),reinterpret_cast<void(*)(void*)>(&d19iterate),0,0,0,0,0}}},
                /*** MsgisoGetISOLanguageInfoResponse */
                /*774*/ { { {&d19field_equals_default,&d19set_field_to_default,1,Sid::Field::FLD_FIRST|Sid::Field::FLD_LIST,Sid::Field::KIND_STRING, MsgisoGetISOLanguageInfoResponse::END,0} } },
                { { { reinterpret_cast<bool(*)(const void*)>(&d19append),reinterpret_cast<void(*)(void*)>(&d19iterate),0,0,0,0,0}}},
                /*776*/ { { {&d19field_equals_default,&d19set_field_to_default,2,Sid::Field::FLD_LIST,Sid::Field::KIND_STRING, (unsigned short) (size_t) &reinterpret_cast<MsgisoGetISOLanguageInfoResponse*>(base_address)->languageNameList,0} } },
                { { { reinterpret_cast<bool(*)(const void*)>(&d19append),reinterpret_cast<void(*)(void*)>(&d19iterate),0,0,0,0,0}}},
                /*** MsgisoGetISOCountryInfoResponse */
                /*778*/ { { {&d19field_equals_default,&d19set_field_to_default,1,Sid::Field::FLD_FIRST|Sid::Field::FLD_LIST,Sid::Field::KIND_STRING, MsgisoGetISOCountryInfoResponse::END,0} } },
                { { { reinterpret_cast<bool(*)(const void*)>(&d19append),reinterpret_cast<void(*)(void*)>(&d19iterate),0,0,0,0,0}}},
                /*780*/ { { {&d19field_equals_default,&d19set_field_to_default,2,Sid::Field::FLD_LIST,Sid::Field::KIND_STRING, (unsigned short) (size_t) &reinterpret_cast<MsgisoGetISOCountryInfoResponse*>(base_address)->countryNameList,0} } },
                { { { reinterpret_cast<bool(*)(const void*)>(&d19append),reinterpret_cast<void(*)(void*)>(&d19iterate),0,0,0,0,0}}},
                /*782*/ { { {&d16field_equals_default,&d16set_field_to_default,3,Sid::Field::FLD_LIST,Sid::Field::KIND_UINT, (unsigned short) (size_t) &reinterpret_cast<MsgisoGetISOCountryInfoResponse*>(base_address)->countryPrefixList,0} } },
                { { { reinterpret_cast<bool(*)(const void*)>(&d16append),reinterpret_cast<void(*)(void*)>(&d16iterate),0,0,0,0,0}}},
                /*784*/ { { {&d19field_equals_default,&d19set_field_to_default,4,Sid::Field::FLD_LIST,Sid::Field::KIND_STRING, (unsigned short) (size_t) &reinterpret_cast<MsgisoGetISOCountryInfoResponse*>(base_address)->countryDialExampleList,0} } },
                { { { reinterpret_cast<bool(*)(const void*)>(&d19append),reinterpret_cast<void(*)(void*)>(&d19iterate),0,0,0,0,0}}},
                /*** MsgisoGetISOCountryCodebyPhoneNoRequest */
                /*786*/ { { {&d1field_equals_default,&d1set_field_to_default,1,Sid::Field::FLD_FIRST,Sid::Field::KIND_STRING, MsgisoGetISOCountryCodebyPhoneNoRequest::END,0} } },
                /*** MsgisoGetISOCountryCodebyPhoneNoResponse */
                /*787*/ { { {&d1field_equals_default,&d1set_field_to_default,1,Sid::Field::FLD_FIRST,Sid::Field::KIND_STRING, MsgisoGetISOCountryCodebyPhoneNoResponse::END,0} } },
                /*** Msgapp2appApp2AppCreateRequest */
                /*788*/ { { {&d1field_equals_default,&d1set_field_to_default,1,Sid::Field::FLD_FIRST,Sid::Field::KIND_STRING, Msgapp2appApp2AppCreateRequest::END,0} } },
                /*** Msgapp2appApp2AppCreateResponse */
                /*789*/ { { {&d3field_equals_default,&d3set_field_to_default,1,Sid::Field::FLD_FIRST,Sid::Field::KIND_BOOLEAN, Msgapp2appApp2AppCreateResponse::END,0} } },
                /*** Msgapp2appApp2AppDeleteRequest */
                /*790*/ { { {&d1field_equals_default,&d1set_field_to_default,1,Sid::Field::FLD_FIRST,Sid::Field::KIND_STRING, Msgapp2appApp2AppDeleteRequest::END,0} } },
                /*** Msgapp2appApp2AppDeleteResponse */
                /*791*/ { { {&d3field_equals_default,&d3set_field_to_default,1,Sid::Field::FLD_FIRST,Sid::Field::KIND_BOOLEAN, Msgapp2appApp2AppDeleteResponse::END,0} } },
                /*** Msgapp2appApp2AppConnectRequest */
                /*792*/ { { {&d1field_equals_default,&d1set_field_to_default,1,Sid::Field::FLD_FIRST,Sid::Field::KIND_STRING, Msgapp2appApp2AppConnectRequest::END,0} } },
                /*793*/ { { {&d1field_equals_default,&d1set_field_to_default,2,0,Sid::Field::KIND_STRING, (unsigned short) (size_t) &reinterpret_cast<Msgapp2appApp2AppConnectRequest*>(base_address)->skypename,0} } },
                /*** Msgapp2appApp2AppConnectResponse */
                /*794*/ { { {&d3field_equals_default,&d3set_field_to_default,1,Sid::Field::FLD_FIRST,Sid::Field::KIND_BOOLEAN, Msgapp2appApp2AppConnectResponse::END,0} } },
                /*** Msgapp2appApp2AppDisconnectRequest */
                /*795*/ { { {&d1field_equals_default,&d1set_field_to_default,1,Sid::Field::FLD_FIRST,Sid::Field::KIND_STRING, Msgapp2appApp2AppDisconnectRequest::END,0} } },
                /*796*/ { { {&d1field_equals_default,&d1set_field_to_default,2,0,Sid::Field::KIND_STRING, (unsigned short) (size_t) &reinterpret_cast<Msgapp2appApp2AppDisconnectRequest*>(base_address)->stream,0} } },
                /*** Msgapp2appApp2AppDisconnectResponse */
                /*797*/ { { {&d3field_equals_default,&d3set_field_to_default,1,Sid::Field::FLD_FIRST,Sid::Field::KIND_BOOLEAN, Msgapp2appApp2AppDisconnectResponse::END,0} } },
                /*** Msgapp2appApp2AppWriteRequest */
                /*798*/ { { {&d1field_equals_default,&d1set_field_to_default,1,Sid::Field::FLD_FIRST,Sid::Field::KIND_STRING, Msgapp2appApp2AppWriteRequest::END,0} } },
                /*799*/ { { {&d1field_equals_default,&d1set_field_to_default,2,0,Sid::Field::KIND_STRING, (unsigned short) (size_t) &reinterpret_cast<Msgapp2appApp2AppWriteRequest*>(base_address)->stream,0} } },
                /*800*/ { { {&d11field_equals_default,&d11set_field_to_default,3,0,Sid::Field::KIND_BINARY, (unsigned short) (size_t) &reinterpret_cast<Msgapp2appApp2AppWriteRequest*>(base_address)->data,0} } },
                /*** Msgapp2appApp2AppWriteResponse */
                /*801*/ { { {&d3field_equals_default,&d3set_field_to_default,1,Sid::Field::FLD_FIRST,Sid::Field::KIND_BOOLEAN, Msgapp2appApp2AppWriteResponse::END,0} } },
                /*** Msgapp2appApp2AppDatagramRequest */
                /*802*/ { { {&d1field_equals_default,&d1set_field_to_default,1,Sid::Field::FLD_FIRST,Sid::Field::KIND_STRING, Msgapp2appApp2AppDatagramRequest::END,0} } },
                /*803*/ { { {&d1field_equals_default,&d1set_field_to_default,2,0,Sid::Field::KIND_STRING, (unsigned short) (size_t) &reinterpret_cast<Msgapp2appApp2AppDatagramRequest*>(base_address)->stream,0} } },
                /*804*/ { { {&d11field_equals_default,&d11set_field_to_default,3,0,Sid::Field::KIND_BINARY, (unsigned short) (size_t) &reinterpret_cast<Msgapp2appApp2AppDatagramRequest*>(base_address)->data,0} } },
                /*** Msgapp2appApp2AppDatagramResponse */
                /*805*/ { { {&d3field_equals_default,&d3set_field_to_default,1,Sid::Field::FLD_FIRST,Sid::Field::KIND_BOOLEAN, Msgapp2appApp2AppDatagramResponse::END,0} } },
                /*** Msgapp2appApp2AppReadRequest */
                /*806*/ { { {&d1field_equals_default,&d1set_field_to_default,1,Sid::Field::FLD_FIRST,Sid::Field::KIND_STRING, Msgapp2appApp2AppReadRequest::END,0} } },
                /*807*/ { { {&d1field_equals_default,&d1set_field_to_default,2,0,Sid::Field::KIND_STRING, (unsigned short) (size_t) &reinterpret_cast<Msgapp2appApp2AppReadRequest*>(base_address)->stream,0} } },                /*** Msgapp2appApp2AppReadResponse */
                /*808*/ { { {&d3field_equals_default,&d3set_field_to_default,1,Sid::Field::FLD_FIRST,Sid::Field::KIND_BOOLEAN, Msgapp2appApp2AppReadResponse::END,0} } },
                /*809*/ { { {&d11field_equals_default,&d11set_field_to_default,2,0,Sid::Field::KIND_BINARY, (unsigned short) (size_t) &reinterpret_cast<Msgapp2appApp2AppReadResponse*>(base_address)->data,0} } },
                /*** Msgapp2appApp2AppGetConnectableUsersRequest */
                /*810*/ { { {&d1field_equals_default,&d1set_field_to_default,1,Sid::Field::FLD_FIRST,Sid::Field::KIND_STRING, Msgapp2appApp2AppGetConnectableUsersRequest::END,0} } },
                /*** Msgapp2appApp2AppGetConnectableUsersResponse */
                /*811*/ { { {&d3field_equals_default,&d3set_field_to_default,1,Sid::Field::FLD_FIRST,Sid::Field::KIND_BOOLEAN, Msgapp2appApp2AppGetConnectableUsersResponse::END,0} } },
                /*812*/ { { {&d19field_equals_default,&d19set_field_to_default,2,Sid::Field::FLD_LIST,Sid::Field::KIND_STRING, (unsigned short) (size_t) &reinterpret_cast<Msgapp2appApp2AppGetConnectableUsersResponse*>(base_address)->users,0} } },
                { { { reinterpret_cast<bool(*)(const void*)>(&d19append),reinterpret_cast<void(*)(void*)>(&d19iterate),0,0,0,0,0}}},
                /*** Msgapp2appApp2AppGetStreamsListRequest */
                /*814*/ { { {&d1field_equals_default,&d1set_field_to_default,1,Sid::Field::FLD_FIRST,Sid::Field::KIND_STRING, Msgapp2appApp2AppGetStreamsListRequest::END,0} } },
                /*815*/ { { {&d9field_equals_default,&d9set_field_to_default,2,0,Sid::Field::KIND_ENUM, (unsigned short) (size_t) &reinterpret_cast<Msgapp2appApp2AppGetStreamsListRequest*>(base_address)->listType,0} } },
                /*** Msgapp2appApp2AppGetStreamsListResponse */
                /*816*/ { { {&d3field_equals_default,&d3set_field_to_default,1,Sid::Field::FLD_FIRST,Sid::Field::KIND_BOOLEAN, Msgapp2appApp2AppGetStreamsListResponse::END,0} } },
                /*817*/ { { {&d19field_equals_default,&d19set_field_to_default,2,Sid::Field::FLD_LIST,Sid::Field::KIND_STRING, (unsigned short) (size_t) &reinterpret_cast<Msgapp2appApp2AppGetStreamsListResponse*>(base_address)->streams,0} } },
                { { { reinterpret_cast<bool(*)(const void*)>(&d19append),reinterpret_cast<void(*)(void*)>(&d19iterate),0,0,0,0,0}}},
                /*819*/ { { {&d16field_equals_default,&d16set_field_to_default,3,Sid::Field::FLD_LIST,Sid::Field::KIND_UINT, (unsigned short) (size_t) &reinterpret_cast<Msgapp2appApp2AppGetStreamsListResponse*>(base_address)->receivedSizes,0} } },
                { { { reinterpret_cast<bool(*)(const void*)>(&d16append),reinterpret_cast<void(*)(void*)>(&d16iterate),0,0,0,0,0}}},
                /*** Msgapp2appOnApp2AppDatagram */
                /*821*/ { { {&d1field_equals_default,&d1set_field_to_default,1,Sid::Field::FLD_FIRST,Sid::Field::KIND_STRING, Msgapp2appOnApp2AppDatagram::END,0} } },
                /*822*/ { { {&d1field_equals_default,&d1set_field_to_default,2,0,Sid::Field::KIND_STRING, (unsigned short) (size_t) &reinterpret_cast<Msgapp2appOnApp2AppDatagram*>(base_address)->stream,0} } },
                /*823*/ { { {&d11field_equals_default,&d11set_field_to_default,3,0,Sid::Field::KIND_BINARY, (unsigned short) (size_t) &reinterpret_cast<Msgapp2appOnApp2AppDatagram*>(base_address)->data,0} } },
                /*** Msgapp2appOnApp2AppStreamListChange */
                /*824*/ { { {&d1field_equals_default,&d1set_field_to_default,1,Sid::Field::FLD_FIRST,Sid::Field::KIND_STRING, Msgapp2appOnApp2AppStreamListChange::END,0} } },
                /*825*/ { { {&d9field_equals_default,&d9set_field_to_default,2,0,Sid::Field::KIND_ENUM, (unsigned short) (size_t) &reinterpret_cast<Msgapp2appOnApp2AppStreamListChange*>(base_address)->listType,0} } },
                /*826*/ { { {&d19field_equals_default,&d19set_field_to_default,3,Sid::Field::FLD_LIST,Sid::Field::KIND_STRING, (unsigned short) (size_t) &reinterpret_cast<Msgapp2appOnApp2AppStreamListChange*>(base_address)->streams,0} } },
                { { { reinterpret_cast<bool(*)(const void*)>(&d19append),reinterpret_cast<void(*)(void*)>(&d19iterate),0,0,0,0,0}}},
                /*828*/ { { {&d16field_equals_default,&d16set_field_to_default,4,Sid::Field::FLD_LIST,Sid::Field::KIND_UINT, (unsigned short) (size_t) &reinterpret_cast<Msgapp2appOnApp2AppStreamListChange*>(base_address)->receivedSizes,0} } },
                { { { reinterpret_cast<bool(*)(const void*)>(&d16append),reinterpret_cast<void(*)(void*)>(&d16iterate),0,0,0,0,0}}},
        };
Sid::Field* Skype::get_property_desc(const uint& modid, const uint& propid) {
        switch (modid) {
        case 10:
                switch (propid) {
                case 151: return &skylibFields[33];
                case 152: return &skylibFields[34];
                case 153: return &skylibFields[35];
                case 154: return &skylibFields[36];
                case 155: return &skylibFields[37];
                default: break;
                }
                break;
        case 2:
                switch (propid) {
                case 4: return &skylibFields[90];
                case 5: return &skylibFields[91];
                case 6: return &skylibFields[92];
                case 7: return &skylibFields[93];
                case 8: return &skylibFields[94];
                case 9: return &skylibFields[95];
                case 10: return &skylibFields[96];
                case 11: return &skylibFields[97];
                case 12: return &skylibFields[98];
                case 13: return &skylibFields[99];
                case 14: return &skylibFields[100];
                case 15: return &skylibFields[101];
                case 16: return &skylibFields[102];
                case 17: return &skylibFields[103];
                case 18: return &skylibFields[104];
                case 19: return &skylibFields[105];
                case 20: return &skylibFields[106];
                case 21: return &skylibFields[107];
                case 22: return &skylibFields[108];
                case 23: return &skylibFields[109];
                case 25: return &skylibFields[110];
                case 26: return &skylibFields[111];
                case 27: return &skylibFields[112];
                case 28: return &skylibFields[113];
                case 29: return &skylibFields[114];
                case 33: return &skylibFields[115];
                case 34: return &skylibFields[116];
                case 35: return &skylibFields[117];
                case 36: return &skylibFields[118];
                case 37: return &skylibFields[119];
                case 39: return &skylibFields[120];
                case 41: return &skylibFields[121];
                case 42: return &skylibFields[122];
                case 180: return &skylibFields[123];
                case 182: return &skylibFields[124];
                case 183: return &skylibFields[125];
                case 184: return &skylibFields[126];
                case 185: return &skylibFields[127];
                case 186: return &skylibFields[128];
                case 187: return &skylibFields[129];
                case 188: return &skylibFields[130];
                case 189: return &skylibFields[131];
                case 202: return &skylibFields[132];
                case 205: return &skylibFields[133];
                default: break;
                }
                break;
        case 1:
                switch (propid) {
                case 200: return &skylibFields[196];
                default: break;
                }
                break;
        case 19:
                switch (propid) {
                case 930: return &skylibFields[225];
                case 931: return &skylibFields[226];
                case 932: return &skylibFields[227];
                case 933: return &skylibFields[228];
                case 934: return &skylibFields[229];
                case 935: return &skylibFields[230];
                case 936: return &skylibFields[231];
                case 938: return &skylibFields[232];
                case 939: return &skylibFields[233];
                case 941: return &skylibFields[234];
                case 942: return &skylibFields[235];
                case 943: return &skylibFields[236];
                case 947: return &skylibFields[237];
                case 948: return &skylibFields[238];
                case 949: return &skylibFields[239];
                case 950: return &skylibFields[240];
                case 951: return &skylibFields[241];
                case 952: return &skylibFields[242];
                case 953: return &skylibFields[243];
                case 954: return &skylibFields[244];
                default: break;
                }
                break;
        case 18:
                switch (propid) {
                case 902: return &skylibFields[357];
                case 903: return &skylibFields[358];
                case 904: return &skylibFields[359];
                case 906: return &skylibFields[360];
                case 907: return &skylibFields[361];
                case 909: return &skylibFields[362];
                case 910: return &skylibFields[363];
                case 911: return &skylibFields[364];
                case 913: return &skylibFields[365];
                case 914: return &skylibFields[366];
                case 915: return &skylibFields[367];
                case 918: return &skylibFields[368];
                case 919: return &skylibFields[369];
                case 920: return &skylibFields[370];
                case 921: return &skylibFields[371];
                case 922: return &skylibFields[372];
                case 924: return &skylibFields[373];
                case 925: return &skylibFields[374];
                case 927: return &skylibFields[375];
                case 928: return &skylibFields[376];
                case 970: return &skylibFields[377];
                case 971: return &skylibFields[378];
                case 972: return &skylibFields[379];
                case 973: return &skylibFields[380];
                case 974: return &skylibFields[381];
                case 975: return &skylibFields[382];
                case 976: return &skylibFields[383];
                case 977: return &skylibFields[384];
                case 979: return &skylibFields[385];
                case 980: return &skylibFields[386];
                case 981: return &skylibFields[387];
                case 996: return &skylibFields[388];
                default: break;
                }
                break;
        case 9:
                switch (propid) {
                case 120: return &skylibFields[422];
                case 121: return &skylibFields[423];
                case 122: return &skylibFields[424];
                case 123: return &skylibFields[425];
                case 125: return &skylibFields[426];
                case 126: return &skylibFields[427];
                case 127: return &skylibFields[428];
                case 222: return &skylibFields[429];
                case 223: return &skylibFields[430];
                case 790: return &skylibFields[431];
                case 792: return &skylibFields[432];
                case 960: return &skylibFields[433];
                case 961: return &skylibFields[434];
                case 962: return &skylibFields[435];
                case 963: return &skylibFields[436];
                case 964: return &skylibFields[437];
                case 966: return &skylibFields[438];
                case 968: return &skylibFields[439];
                case 982: return &skylibFields[440];
                default: break;
                }
                break;
        case 11:
                switch (propid) {
                case 130: return &skylibFields[485];
                case 131: return &skylibFields[486];
                case 132: return &skylibFields[487];
                case 133: return &skylibFields[488];
                case 134: return &skylibFields[489];
                case 1104: return &skylibFields[490];
                case 1105: return &skylibFields[491];
                default: break;
                }
                break;
        case 7:
                switch (propid) {
                case 100: return &skylibFields[516];
                case 101: return &skylibFields[517];
                case 102: return &skylibFields[518];
                case 103: return &skylibFields[519];
                case 104: return &skylibFields[520];
                case 105: return &skylibFields[521];
                case 106: return &skylibFields[522];
                case 107: return &skylibFields[523];
                case 108: return &skylibFields[524];                case 109: return &skylibFields[525];
                case 830: return &skylibFields[526];
                case 831: return &skylibFields[527];
                default: break;
                }
                break;
        case 12:
                switch (propid) {
                case 48: return &skylibFields[594];
                case 49: return &skylibFields[595];
                case 190: return &skylibFields[596];
                case 191: return &skylibFields[597];
                case 192: return &skylibFields[598];
                case 193: return &skylibFields[599];
                case 194: return &skylibFields[600];
                case 195: return &skylibFields[601];
                case 196: return &skylibFields[602];
                case 197: return &skylibFields[603];
                case 198: return &skylibFields[604];
                case 199: return &skylibFields[605];
                case 840: return &skylibFields[606];
                default: break;
                }
                break;
        case 6:
                switch (propid) {
                case 80: return &skylibFields[620];
                case 81: return &skylibFields[621];
                case 82: return &skylibFields[622];
                case 83: return &skylibFields[623];
                case 84: return &skylibFields[624];
                case 85: return &skylibFields[625];
                case 86: return &skylibFields[626];
                case 87: return &skylibFields[627];
                case 88: return &skylibFields[628];
                case 89: return &skylibFields[629];
                case 90: return &skylibFields[630];
                case 91: return &skylibFields[631];
                case 92: return &skylibFields[632];
                case 93: return &skylibFields[633];
                case 98: return &skylibFields[634];
                default: break;
                }
                break;
        case 5:
                switch (propid) {
                case 4: return &skylibFields[689];
                case 5: return &skylibFields[690];
                case 7: return &skylibFields[691];
                case 8: return &skylibFields[692];
                case 9: return &skylibFields[693];
                case 10: return &skylibFields[694];
                case 11: return &skylibFields[695];
                case 12: return &skylibFields[696];
                case 13: return &skylibFields[697];
                case 14: return &skylibFields[698];
                case 15: return &skylibFields[699];
                case 16: return &skylibFields[700];
                case 17: return &skylibFields[701];
                case 18: return &skylibFields[702];
                case 19: return &skylibFields[703];
                case 26: return &skylibFields[704];
                case 27: return &skylibFields[705];
                case 28: return &skylibFields[706];
                case 34: return &skylibFields[707];
                case 37: return &skylibFields[708];
                case 70: return &skylibFields[709];
                case 71: return &skylibFields[710];
                case 72: return &skylibFields[711];
                case 73: return &skylibFields[712];
                case 74: return &skylibFields[713];
                case 75: return &skylibFields[714];
                case 76: return &skylibFields[715];
                case 77: return &skylibFields[716];
                case 78: return &skylibFields[717];
                case 79: return &skylibFields[718];
                case 160: return &skylibFields[719];
                case 161: return &skylibFields[720];
                case 162: return &skylibFields[721];
                case 163: return &skylibFields[722];
                case 164: return &skylibFields[723];
                case 165: return &skylibFields[724];
                case 166: return &skylibFields[725];
                case 168: return &skylibFields[726];
                case 169: return &skylibFields[727];
                case 182: return &skylibFields[728];
                case 183: return &skylibFields[729];
                case 205: return &skylibFields[730];
                case 773: return &skylibFields[731];
                case 800: return &skylibFields[732];
                case 801: return &skylibFields[733];
                case 802: return &skylibFields[734];
                case 804: return &skylibFields[735];
                default: break;
                }
                break;
        }
        return 0;
};
#       ifdef SKYPE_SID_ADDLABELS_IN_DESCRIPTORS
        const char* skylibNames[] = {
                "version",
                "objectID",
                "name",
                "objectID",
                "result",
                "objectID",
                "conversations",
                "objectID",
                "conversation",
                "result",
                "objectID",
                "conversation",
                "objectID",
                "result",
                "objectID",
                "conversation",
                "objectID",
                "conversation",
                "objectID",
                "contacts",
                "objectID",
                "contact",
                "result",
                "objectID",
                "contact",
                "objectID",
                "result",
                "objectID",
                "contact",
                "objectID",
                "contact",
                "given_displayname",
                "nrofcontacts",
                "nrofcontacts_online",
                "custom_group_id",
                "type",
                "type",
                "contactGroup",
                "groups",
                "group",
                "group",
                "objectID",
                "type",
                "objectID",
                "identity",
                "objectID",
                "present",
                "avatar",
                "objectID",
                "email",
                "objectID",
                "company",
                "objectID",
                "group",
                "result",
                "objectID",
                "groupType",
                "result",
                "objectID",
                "blocked",
                "abuse",
                "objectID",
                "objectID",
                "name",
                "objectID",
                "isMyBuddy",
                "syncAuth",
                "objectID",
                "message",
                "extras_bitmask",
                "objectID",
                "result",
                "objectID",
                "num",
                "label",
                "number",
                "objectID",
                "conversation",
                "objectID",
                "capability",
                "queryServer",
                "result",
                "objectID",
                "capability",
                "queryServer",
                "status",
                "objectID",
                "skypename",
                "fullname",
                "pstnnumber",
                "birthday",
                "gender",
                "languages",
                "country",
                "province",
                "city",
                "phone_home",
                "phone_office",
                "phone_mobile",
                "emails",
                "homepage",
                "about",
                "profile_timestamp",
                "received_authrequest",
                "displayname",
                "refreshing",
                "given_authlevel",
                "authreq_timestamp",
                "mood_text",
                "timezone",
                "nrof_authed_buddies",
                "ipcountry",
                "given_displayname",
                "availability",
                "lastonline_timestamp",
                "capabilities",
                "avatar_image",
                "lastused_timestamp",
                "authrequest_count",
                "popularity_ord",
                "assigned_comment",
                "avatar_timestamp",
                "mood_timestamp",
                "assigned_phone1",
                "assigned_phone1_label",
                "assigned_phone2",
                "assigned_phone2_label",
                "assigned_phone3",
                "assigned_phone3_label",
                "type",
                "rich_mood_text",
                "identity",
                "type",
                "identity",
                "contact",
                "number",
                "found",
                "contact",
                "foundInKey",
                "identity",
                "type",
                "original",
                "isNewSkypeName",
                "result",
                "normalized",
                "original",
                "countryPrefix",
                "result",
                "normalized",
                "contact",
                "contact",
                "objectID",
                "min_age_in_years",
                "add_to_subs",
                "valid",
                "objectID",
                "max_age_in_years",
                "add_to_subs",
                "valid",
                "objectID",
                "email",
                "add_to_subs",
                "valid",
                "objectID",
                "language",
                "add_to_subs",
                "valid",
                "objectID",
                "prop",
                "cond",
                "value",
                "add_to_subs",
                "valid",
                "objectID",
                "prop",
                "cond",
                "value",
                "add_to_subs",
                "valid",
                "objectID",
                "objectID",
                "result",
                "objectID",
                "objectID",
                "objectID",
                "objectID",
                "from",
                "count",
                "contacts",
                "objectID",
                "contact",
                "rankValue",
                "contact_search_status",
                "rangeList",
                "search",
                "text",
                "search",
                "identity",
                "search",
                "objectID",
                "rank",
                "result",
                "objectID",
                "rank",
                "objectID",
                "identityToUse",
                "videoCall",
                "nrofRedials",
                "redialPeriod",
                "autoStartVM",
                "origin",
                "objectID",
                "objectID",
                "identityToUse",
                "objectID",
                "video",
                "objectID",
                "objectID",
                "objectID",
                "dtmf",
                "convo_id",
                "identity",
                "rank",
                "requested_rank",
                "text_status",
                "voice_status",
                "video_status",
                "live_price_for_me",
                "live_start_timestamp",
                "sound_level",
                "debuginfo",
                "live_identity",
                "last_voice_error",
                "live_fwd_identities",
                "quality_problems",
                "live_type",
                "live_country",
                "transferred_by",
                "transferred_to",
                "adder",
                "objectID",
                "propKey",
                "value",
                "objectID",
                "topic",
                "isXML",
                "objectID",
                "guidelines",
                "isXML",
                "objectID",
                "jpeg",
                "objectID",
                "identitiesToAdd",
                "conference",
                "objectID",
                "identities",
                "objectID",
                "otherConversation",
                "conversation",
                "objectID",
                "accessToken",
                "objectID",
                "identities",
                "videoCall",
                "origin",
                "objectID",
                "objectID",
                "objectID",
                "objectID",
                "objectID",
                "postVoiceAutoresponse",
                "objectID",
                "objectID",
                "identities",
                "transferTopic",
                "objectID",
                "identity",
                "result",
                "objectID",                "dtmf",
                "lengthInMS",
                "objectID",
                "objectID",
                "status",
                "objectID",
                "text",
                "isXML",
                "message",
                "objectID",
                "contacts",
                "objectID",
                "paths",
                "body",
                "error_code",
                "error_file",
                "objectID",
                "voicemail",
                "body",
                "objectID",
                "sms",
                "body",
                "objectID",
                "blob",
                "objectID",
                "objectID",
                "password",
                "objectID",
                "password",
                "hint",
                "objectID",
                "objectID",
                "objectID",
                "name",
                "objectID",
                "bookmark",
                "objectID",
                "alertString",
                "objectID",
                "objectID",
                "timestamp",
                "objectID",
                "timestamp",
                "also_unconsume",
                "objectID",
                "objectID",
                "group",
                "result",
                "objectID",
                "filter",
                "participants",
                "objectID",
                "requireTimestamp",
                "contextMessages",
                "unconsumedMessages",
                "objectID",
                "text",
                "fromTimestampUp",
                "message",
                "objectID",
                "objectID",
                "message",
                "objectID",
                "spawned",
                "type",
                "creator",
                "creation_timestamp",
                "opt_entry_level_rank",
                "opt_disclose_history",
                "opt_admin_only_activities",
                "meta_name",
                "meta_topic",
                "meta_guidelines",
                "meta_picture",
                "spawned_from_convo_id",
                "live_host",
                "my_status",
                "alert_string",
                "is_bookmarked",
                "opt_joining_enabled",
                "displayname",
                "given_displayname",
                "local_livestatus",
                "inbox_timestamp",
                "unconsumed_messages_voice",
                "active_vm_id",
                "identity",
                "inbox_message_id",
                "live_start_timestamp",
                "unconsumed_suppressed_messages",
                "unconsumed_normal_messages",
                "unconsumed_elevated_messages",
                "consumption_horizon",
                "passwordhint",
                "last_activity_timestamp",
                "live_is_muted",
                "conference",
                "convoIdentity",
                "conversation",
                "participantIdentities",
                "createIfNonExisting",
                "ignoreBookmarkedOrNamed",
                "conversation",
                "joinBlob",
                "alsoJoin",
                "conversation",
                "type",
                "conversations",
                "conversation",
                "type",
                "added",
                "objectID",
                "result",
                "objectID",
                "newText",
                "isXML",
                "objectID",
                "contacts",
                "objectID",
                "transfers",
                "objectID",
                "voicemail",
                "objectID",
                "sms",
                "objectID",
                "convo_guid",
                "timestamp",
                "author",
                "author_displayname",
                "identities",
                "leavereason",
                "body_xml",
                "edited_by",
                "edit_timestamp",
                "originally_meant_for",
                "guid",
                "convo_id",
                "type",
                "sending_status",
                "param_key",
                "param_value",
                "reason",
                "consumption_status",
                "participant_count",
                "guid",
                "message",
                "message",
                "changesInboxTimestamp",
                "supersedesHistoryMessage",
                "conversation",
                "objectID",
                "windowh",
                "objectID",
                "objectID",
                "objectID",
                "ret",
                "requestId",
                "objectID",
                "requestId",
                "isSuccessful",
                "image",
                "width",
                "height",
                "objectID",
                "x0",
                "y0",
                "width",
                "height",
                "monitorNumber",
                "windowHandle",
                "objectID",
                "x0",
                "y0",
                "width",
                "height",
                "objectID",
                "mediaType",
                "webcamName",
                "devicePath",
                "updateSetup",
                "objectID",
                "mediatype",
                "deviceName",
                "devicePath",
                "objectID",
                "image",
                "width",
                "height",
                "status",
                "error",
                "debuginfo",
                "dimensions",
                "media_type",
                "convo_id",
                "device_path",
                "deviceNames",
                "devicePaths",
                "count",
                "deviceName",
                "devicePath",
                "cap",
                "deviceName",
                "devicePath",
                "type",
                "deviceName",
                "devicePath",
                "video",
                "command",
                "response",
                "objectID",
                "objectID",
                "objectID",
                "objectID",
                "objectID",
                "objectID",
                "objectID",
                "result",
                "type",
                "partner_handle",
                "partner_dispname",
                "status",
                "failurereason",
                "subject",
                "timestamp",
                "duration",
                "allowed_duration",
                "playback_progress",
                "convo_id",
                "chatmsg_guid",
                "skypeName",
                "greeting",
                "soundid",
                "sound",
                "loop",
                "useCallOutDevice",
                "soundid",
                "datafile",
                "loop",
                "useCallOutDevice",
                "result",
                "soundid",
                "recordAndPlaybackData",
                "handleList",
                "nameList",
                "productIdList",
                "handleList",
                "nameList",
                "productIdList",
                "callInDevice",
                "callOutDevice",
                "waveOutDevice",
                "deviceHandle",
                "interfaceString",
                "capabilities",
                "micLevel",
                "speakerLevel",
                "command",
                "response",
                "volume",
                "volume",
                "micVolume",
                "volume",
                "muted",
                "muted",
                "mute",
                "mute",
                "media",
                "maxUplinkBps",
                "maxDownlinkBps",
                "objectID",
                "target",
                "status",
                "objectID",
                "target",
                "price",
                "objectID",
                "numbers",
                "success",                "objectID",
                "text",
                "result",
                "chunks",
                "charsUntilNextChunk",
                "objectID",
                "textChunks",
                "charsUntilNextChunk",
                "is_failed_unseen",
                "price_precision",
                "type",
                "status",
                "failurereason",
                "price",
                "price_currency",
                "target_numbers",
                "target_statuses",
                "body",
                "timestamp",
                "reply_to_number",
                "chatmsg_id",
                "type",
                "number",
                "sms",
                "number",
                "code",
                "sms",
                "sms",
                "objectID",
                "filenameWithPath",
                "success",
                "objectID",
                "objectID",
                "objectID",
                "type",
                "partner_handle",
                "partner_dispname",
                "status",
                "failurereason",
                "starttime",
                "finishtime",
                "filepath",
                "filename",
                "filesize",
                "bytestransferred",
                "bytespersecond",
                "chatmsg_guid",
                "chatmsg_index",
                "convo_id",
                "objectID",
                "status",
                "progress",
                "objectID",
                "setAvailabilityTo",
                "objectID",
                "password",
                "savePwd",
                "saveDataLocally",
                "objectID",
                "password",
                "savePwd",
                "saveDataLocally",
                "email",
                "allowSpam",
                "objectID",
                "clearSavedPwd",
                "objectID",
                "oldPassword",
                "newPassword",
                "savePwd",
                "objectID",
                "savePwd",
                "objectID",
                "propKey",
                "value",
                "objectID",
                "propKey",
                "value",
                "objectID",
                "objectID",
                "propKey",
                "value",
                "objectID",
                "propKey",
                "value",
                "objectID",
                "propKey",
                "value",
                "objectID",
                "availability",
                "objectID",
                "standby",
                "objectID",
                "capability",
                "status",
                "expiryTimestamp",
                "objectID",
                "skypenameHash",
                "objectID",
                "email",
                "objectID",
                "company",
                "objectID",
                "skypename",
                "fullname",
                "birthday",
                "gender",
                "languages",
                "country",
                "province",
                "city",
                "phone_home",
                "phone_office",
                "phone_mobile",
                "emails",
                "homepage",
                "about",
                "profile_timestamp",
                "mood_text",
                "timezone",
                "nrof_authed_buddies",
                "availability",
                "avatar_image",
                "status",
                "pwdchangestatus",
                "suggested_skypename",
                "logoutreason",
                "skypeout_balance_currency",
                "skypeout_balance",
                "skypein_numbers",
                "offline_callforward",
                "commitstatus",
                "cblsyncstatus",
                "chat_policy",
                "skype_call_policy",
                "pstn_call_policy",
                "avatar_policy",
                "buddycount_policy",
                "timezone_policy",
                "webpresence_policy",
                "phonenumbers_policy",
                "voicemail_policy",
                "avatar_timestamp",
                "mood_timestamp",
                "rich_mood_text",
                "partner_optedout",
                "service_provider_info",
                "registration_timestamp",
                "nr_of_other_instances",
                "skypeout_precision",
                "identity",
                "account",
                "accountNameList",
                "account",
                "fullname",
                "suggestedName",
                "value",
                "result",
                "freeBytesLeft",
                "propKey",
                "strValue",
                "forRegistration",
                "result",
                "freeBytesLeft",
                "username",
                "password",
                "result",
                "type",
                "port",
                "key",
                "value",
                "key",
                "value",
                "key",
                "value",
                "key",
                "value",
                "key",
                "value",
                "key",
                "value",
                "key",
                "value",
                "key",
                "key",
                "value",
                "languageCodeList",
                "languageNameList",
                "countryCodeList",
                "countryNameList",
                "countryPrefixList",
                "countryDialExampleList",
                "number",
                "countryCode",
                "appname",
                "result",
                "appname",
                "result",
                "appname",
                "skypename",
                "result",
                "appname",
                "stream",
                "result",
                "appname",
                "stream",
                "data",
                "result",
                "appname",
                "stream",
                "data",
                "result",
                "appname",
                "stream",
                "result",
                "data",
                "appname",
                "result",
                "users",
                "appname",
                "listType",
                "result",
                "streams",
                "receivedSizes",
                "appname",
                "stream",
                "data",
                "appname",
                "listType",
                "streams",
                "receivedSizes",
        };
#       endif /* SKYPE_SID_ADDLABELS_IN_DESCRIPTORS*/
#ifdef SE_USE_NAMESPACE
} // skylib
#endif
