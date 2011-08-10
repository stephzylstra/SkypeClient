#ifndef __SIDG_MSGS_SKYLIBHPP_INCLUDED__
#define __SIDG_MSGS_SKYLIBHPP_INCLUDED__

#include "sidg_skylibrefs.hpp"

#ifdef SE_USE_NAMESPACE
namespace skylib {
#endif
        extern Sid::Field skylibFields[];
        struct MsgconfigGetVersionStringResponse {
                Sid::String version;
                enum { BEGIN = 0, END = 1 };
        };
        struct MsgcontactContactGroupGiveDisplayNameRequest {
                ContactGroupRef objectID;
                Sid::String     name;
                enum { BEGIN = 1, END = 3 };
        };
        struct MsgcontactContactGroupDeleteRequest {
                ContactGroupRef objectID;
                enum { BEGIN = 3, END = 4 };
        };
        struct MsgcontactContactGroupDeleteResponse {
                bool result;
                enum { BEGIN = 4, END = 5 };
        };
        struct MsgcontactContactGroupGetConversationsRequest {
                ContactGroupRef objectID;
                enum { BEGIN = 5, END = 6 };
        };
        struct MsgcontactContactGroupGetConversationsResponse {
                ConversationRefs conversations;
                enum { BEGIN = 6, END = 8 };
        };
        struct MsgcontactContactGroupCanAddConversationRequest {
                ContactGroupRef objectID;
                ConversationRef conversation;
                enum { BEGIN = 8, END = 10 };
        };
        struct MsgcontactContactGroupCanAddConversationResponse {
                bool result;
                enum { BEGIN = 10, END = 11 };
        };
        struct MsgcontactContactGroupAddConversationRequest {
                ContactGroupRef objectID;
                ConversationRef conversation;
                enum { BEGIN = 11, END = 13 };
        };
        struct MsgcontactContactGroupCanRemoveConversationRequest {
                ContactGroupRef objectID;
                enum { BEGIN = 13, END = 14 };
        };
        struct MsgcontactContactGroupCanRemoveConversationResponse {
                bool result;
                enum { BEGIN = 14, END = 15 };
        };
        struct MsgcontactContactGroupRemoveConversationRequest {
                ContactGroupRef objectID;
                ConversationRef conversation;
                enum { BEGIN = 15, END = 17 };
        };
        struct MsgcontactContactGroupOnChangeConversation {
                ContactGroupRef objectID;
                ConversationRef conversation;
                enum { BEGIN = 17, END = 19 };
        };
        struct MsgcontactContactGroupGetContactsRequest {
                ContactGroupRef objectID;
                enum { BEGIN = 19, END = 20 };
        };
        struct MsgcontactContactGroupGetContactsResponse {
                ContactRefs contacts;
                enum { BEGIN = 20, END = 22 };
        };
        struct MsgcontactContactGroupCanAddContactRequest {
                ContactGroupRef objectID;
                ContactRef      contact;
                enum { BEGIN = 22, END = 24 };
        };
        struct MsgcontactContactGroupCanAddContactResponse {
                bool result;
                enum { BEGIN = 24, END = 25 };
        };
        struct MsgcontactContactGroupAddContactRequest {
                ContactGroupRef objectID;
                ContactRef      contact;
                enum { BEGIN = 25, END = 27 };
        };
        struct MsgcontactContactGroupCanRemoveContactRequest {
                ContactGroupRef objectID;
                enum { BEGIN = 27, END = 28 };
        };
        struct MsgcontactContactGroupCanRemoveContactResponse {
                bool result;
                enum { BEGIN = 28, END = 29 };
        };
        struct MsgcontactContactGroupRemoveContactRequest {
                ContactGroupRef objectID;
                ContactRef      contact;
                enum { BEGIN = 29, END = 31 };
        };
        struct MsgcontactContactGroupOnChange {
                ContactGroupRef objectID;
                ContactRef      contact;
                enum { BEGIN = 31, END = 33 };
        };
        struct MsgcontactContactGroup {
                Sid::String given_displayname;
                uint        nrofcontacts;
                uint        nrofcontacts_online;
                uint        custom_group_id;
                int         type;
                Sid::List_uint cachedProps;
                enum { BEGIN = 33, END = 38 };
        };
        struct MsgcontactGetHardwiredContactGroupRequest {
                int type;
                enum { BEGIN = 38, END = 39 };
        };
        struct MsgcontactGetHardwiredContactGroupResponse {
                ContactGroupRef contactGroup;
                enum { BEGIN = 39, END = 40 };
        };
        struct MsgcontactGetCustomContactGroupsResponse {
                ContactGroupRefs groups;
                enum { BEGIN = 40, END = 42 };
        };
        struct MsgcontactCreateCustomContactGroupResponse {
                ContactGroupRef group;
                enum { BEGIN = 42, END = 43 };
        };
        struct MsgcontactOnNewCustomContactGroup {
                ContactGroupRef group;
                enum { BEGIN = 43, END = 44 };
        };
        struct MsgcontactContactGetTypeRequest {
                ContactRef objectID;
                enum { BEGIN = 44, END = 45 };
        };
        struct MsgcontactContactGetTypeResponse {
                int type;
                enum { BEGIN = 45, END = 46 };
        };
        struct MsgcontactContactGetIdentityRequest {
                ContactRef objectID;
                enum { BEGIN = 46, END = 47 };
        };
        struct MsgcontactContactGetIdentityResponse {
                Sid::String identity;
                enum { BEGIN = 47, END = 48 };
        };
        struct MsgcontactContactGetAvatarRequest {
                ContactRef objectID;
                enum { BEGIN = 48, END = 49 };
        };
        struct MsgcontactContactGetAvatarResponse {
                bool        present;
                Sid::Binary avatar;
                enum { BEGIN = 49, END = 51 };
        };
        struct MsgcontactContactGetVerifiedEmailRequest {
                ContactRef objectID;
                enum { BEGIN = 51, END = 52 };
        };
        struct MsgcontactContactGetVerifiedEmailResponse {
                Sid::String email;
                enum { BEGIN = 52, END = 53 };
        };
        struct MsgcontactContactGetVerifiedCompanyRequest {
                ContactRef objectID;
                enum { BEGIN = 53, END = 54 };
        };
        struct MsgcontactContactGetVerifiedCompanyResponse {
                Sid::String company;
                enum { BEGIN = 54, END = 55 };
        };
        struct MsgcontactContactIsMemberOfRequest {
                ContactRef      objectID;
                ContactGroupRef group;
                enum { BEGIN = 55, END = 57 };
        };
        struct MsgcontactContactIsMemberOfResponse {
                bool result;
                enum { BEGIN = 57, END = 58 };
        };
        struct MsgcontactContactIsMemberOfHardwiredGroupRequest {
                ContactRef objectID;
                int        groupType;
                enum { BEGIN = 58, END = 60 };
        };
        struct MsgcontactContactIsMemberOfHardwiredGroupResponse {
                bool result;
                enum { BEGIN = 60, END = 61 };
        };
        struct MsgcontactContactSetBlockedRequest {
                ContactRef objectID;
                bool       blocked;
                bool       abuse;
                enum { BEGIN = 61, END = 64 };
        };
        struct MsgcontactContactIgnoreAuthRequestRequest {
                ContactRef objectID;
                enum { BEGIN = 64, END = 65 };
        };
        struct MsgcontactContactGiveDisplayNameRequest {
                ContactRef  objectID;
                Sid::String name;
                enum { BEGIN = 65, END = 67 };
        };
        struct MsgcontactContactSetBuddyStatusRequest {
                ContactRef objectID;
                bool       isMyBuddy;
                bool       syncAuth;
                enum { BEGIN = 67, END = 70 };
        };
        struct MsgcontactContactSendAuthRequestRequest {
                ContactRef  objectID;
                Sid::String message;
                uint        extras_bitmask;                enum { BEGIN = 70, END = 73 };
        };
        struct MsgcontactContactHasAuthorizedMeRequest {
                ContactRef objectID;
                enum { BEGIN = 73, END = 74 };
        };
        struct MsgcontactContactHasAuthorizedMeResponse {
                bool result;
                enum { BEGIN = 74, END = 75 };
        };
        struct MsgcontactContactSetPhoneNumberRequest {
                ContactRef  objectID;
                uint        num;
                Sid::String label;
                Sid::String number;
                enum { BEGIN = 75, END = 79 };
        };
        struct MsgcontactContactOpenConversationRequest {
                ContactRef objectID;
                enum { BEGIN = 79, END = 80 };
        };
        struct MsgcontactContactOpenConversationResponse {
                ConversationRef conversation;
                enum { BEGIN = 80, END = 81 };
        };
        struct MsgcontactContactHasCapabilityRequest {
                ContactRef objectID;
                int        capability;
                bool       queryServer;
                enum { BEGIN = 81, END = 84 };
        };
        struct MsgcontactContactHasCapabilityResponse {
                bool result;
                enum { BEGIN = 84, END = 85 };
        };
        struct MsgcontactContactGetCapabilityStatusRequest {
                ContactRef objectID;
                int        capability;
                bool       queryServer;
                enum { BEGIN = 85, END = 88 };
        };
        struct MsgcontactContactGetCapabilityStatusResponse {
                int status;
                enum { BEGIN = 88, END = 89 };
        };
        struct MsgcontactContactRefreshProfileRequest {
                ContactRef objectID;
                enum { BEGIN = 89, END = 90 };
        };
        struct MsgcontactContact {
                Sid::String skypename;
                Sid::String fullname;
                Sid::String pstnnumber;
                uint        birthday;
                uint        gender;
                Sid::String languages;
                Sid::String country;
                Sid::String province;
                Sid::String city;
                Sid::String phone_home;
                Sid::String phone_office;
                Sid::String phone_mobile;
                Sid::String emails;
                Sid::String homepage;
                Sid::String about;
                uint        profile_timestamp;
                Sid::String received_authrequest;
                Sid::String displayname;
                bool        refreshing;
                int         given_authlevel;
                uint        authreq_timestamp;
                Sid::String mood_text;
                uint        timezone;
                uint        nrof_authed_buddies;
                Sid::String ipcountry;
                Sid::String given_displayname;
                int         availability;
                uint        lastonline_timestamp;
                Sid::Binary capabilities;
                Sid::Binary avatar_image;
                uint        lastused_timestamp;
                uint        authrequest_count;
                uint        popularity_ord;
                Sid::String assigned_comment;
                uint        avatar_timestamp;
                uint        mood_timestamp;
                Sid::String assigned_phone1;
                Sid::String assigned_phone1_label;
                Sid::String assigned_phone2;
                Sid::String assigned_phone2_label;
                Sid::String assigned_phone3;
                Sid::String assigned_phone3_label;
                int         type;
                Sid::String rich_mood_text;
                Sid::List_uint cachedProps;
                enum { BEGIN = 90, END = 134 };
        };
        struct MsgcontactGetContactTypeRequest {
                Sid::String identity;
                enum { BEGIN = 134, END = 135 };
        };
        struct MsgcontactGetContactTypeResponse {
                int type;
                enum { BEGIN = 135, END = 136 };
        };
        struct MsgcontactGetContactRequest {
                Sid::String identity;
                enum { BEGIN = 136, END = 137 };
        };
        struct MsgcontactGetContactResponse {
                ContactRef contact;
                enum { BEGIN = 137, END = 138 };
        };
        struct MsgcontactFindContactByPstnNumberRequest {
                Sid::String number;
                enum { BEGIN = 138, END = 139 };
        };
        struct MsgcontactFindContactByPstnNumberResponse {
                bool       found;
                ContactRef contact;
                uint       foundInKey;
                enum { BEGIN = 139, END = 142 };
        };
        struct MsgcontactGetIdentityTypeRequest {
                Sid::String identity;
                enum { BEGIN = 142, END = 143 };
        };
        struct MsgcontactGetIdentityTypeResponse {
                int type;
                enum { BEGIN = 143, END = 144 };
        };
        struct MsgcontactNormalizeIdentityRequest {
                Sid::String original;
                bool        isNewSkypeName;
                enum { BEGIN = 144, END = 146 };
        };
        struct MsgcontactNormalizeIdentityResponse {
                int         result;
                Sid::String normalized;
                enum { BEGIN = 146, END = 148 };
        };
        struct MsgcontactNormalizePSTNWithCountryRequest {
                Sid::String original;
                uint        countryPrefix;
                enum { BEGIN = 148, END = 150 };
        };
        struct MsgcontactNormalizePSTNWithCountryResponse {
                int         result;
                Sid::String normalized;
                enum { BEGIN = 150, END = 152 };
        };
        struct MsgcontactOnContactOnlineAppearance {
                ContactRef contact;
                enum { BEGIN = 152, END = 153 };
        };
        struct MsgcontactOnContactGoneOffline {
                ContactRef contact;
                enum { BEGIN = 153, END = 154 };
        };
        struct MsgcontactsearchContactSearchAddMinAgeTermRequest {
                ContactSearchRef objectID;
                uint             min_age_in_years;
                bool             add_to_subs;
                enum { BEGIN = 154, END = 157 };
        };
        struct MsgcontactsearchContactSearchAddMinAgeTermResponse {
                bool valid;
                enum { BEGIN = 157, END = 158 };
        };
        struct MsgcontactsearchContactSearchAddMaxAgeTermRequest {
                ContactSearchRef objectID;
                uint             max_age_in_years;
                bool             add_to_subs;
                enum { BEGIN = 158, END = 161 };
        };
        struct MsgcontactsearchContactSearchAddMaxAgeTermResponse {
                bool valid;
                enum { BEGIN = 161, END = 162 };
        };
        struct MsgcontactsearchContactSearchAddEmailTermRequest {
                ContactSearchRef objectID;
                Sid::String      email;
                bool             add_to_subs;
                enum { BEGIN = 162, END = 165 };
        };
        struct MsgcontactsearchContactSearchAddEmailTermResponse {
                bool valid;
                enum { BEGIN = 165, END = 166 };
        };
        struct MsgcontactsearchContactSearchAddLanguageTermRequest {
                ContactSearchRef objectID;
                Sid::String      language;
                bool             add_to_subs;
                enum { BEGIN = 166, END = 169 };
        };
        struct MsgcontactsearchContactSearchAddLanguageTermResponse {
                bool valid;
                enum { BEGIN = 169, END = 170 };
        };
        struct MsgcontactsearchContactSearchAddStrTermRequest {
                ContactSearchRef objectID;
                int              prop;
                int              cond;
                Sid::String      value;
                bool             add_to_subs;
                enum { BEGIN = 170, END = 175 };
        };
        struct MsgcontactsearchContactSearchAddStrTermResponse {                bool valid;
                enum { BEGIN = 175, END = 176 };
        };
        struct MsgcontactsearchContactSearchAddIntTermRequest {
                ContactSearchRef objectID;
                int              prop;
                int              cond;
                uint             value;
                bool             add_to_subs;
                enum { BEGIN = 176, END = 181 };
        };
        struct MsgcontactsearchContactSearchAddIntTermResponse {
                bool valid;
                enum { BEGIN = 181, END = 182 };
        };
        struct MsgcontactsearchContactSearchAddOrRequest {
                ContactSearchRef objectID;
                enum { BEGIN = 182, END = 183 };
        };
        struct MsgcontactsearchContactSearchIsValidRequest {
                ContactSearchRef objectID;
                enum { BEGIN = 183, END = 184 };
        };
        struct MsgcontactsearchContactSearchIsValidResponse {
                bool result;
                enum { BEGIN = 184, END = 185 };
        };
        struct MsgcontactsearchContactSearchSubmitRequest {
                ContactSearchRef objectID;
                enum { BEGIN = 185, END = 186 };
        };
        struct MsgcontactsearchContactSearchExtendRequest {
                ContactSearchRef objectID;
                enum { BEGIN = 186, END = 187 };
        };
        struct MsgcontactsearchContactSearchReleaseRequest {
                ContactSearchRef objectID;
                enum { BEGIN = 187, END = 188 };
        };
        struct MsgcontactsearchContactSearchGetResultsRequest {
                ContactSearchRef objectID;
                uint             from;
                uint             count;
                enum { BEGIN = 188, END = 191 };
        };
        struct MsgcontactsearchContactSearchGetResultsResponse {
                ContactRefs contacts;
                enum { BEGIN = 191, END = 193 };
        };
        struct MsgcontactsearchContactSearchOnNewResult {
                ContactSearchRef objectID;
                ContactRef       contact;
                uint             rankValue;
                enum { BEGIN = 193, END = 196 };
        };
        struct MsgcontactsearchContactSearch {
                int contact_search_status;
                Sid::List_uint cachedProps;
                enum { BEGIN = 196, END = 197 };
        };
        struct MsgcontactsearchGetOptimalAgeRangesResponse {
                Sid::List_uint rangeList;
                enum { BEGIN = 197, END = 199 };
        };
        struct MsgcontactsearchCreateContactSearchResponse {
                ContactSearchRef search;
                enum { BEGIN = 199, END = 200 };
        };
        struct MsgcontactsearchCreateBasicContactSearchRequest {
                Sid::String text;
                enum { BEGIN = 200, END = 201 };
        };
        struct MsgcontactsearchCreateBasicContactSearchResponse {
                ContactSearchRef search;
                enum { BEGIN = 201, END = 202 };
        };
        struct MsgcontactsearchCreateIdentitySearchRequest {
                Sid::String identity;
                enum { BEGIN = 202, END = 203 };
        };
        struct MsgcontactsearchCreateIdentitySearchResponse {
                ContactSearchRef search;
                enum { BEGIN = 203, END = 204 };
        };
        struct MsgconversationParticipantCanSetRankToRequest {
                ParticipantRef objectID;
                int            rank;
                enum { BEGIN = 204, END = 206 };
        };
        struct MsgconversationParticipantCanSetRankToResponse {
                bool result;
                enum { BEGIN = 206, END = 207 };
        };
        struct MsgconversationParticipantSetRankToRequest {
                ParticipantRef objectID;
                int            rank;
                enum { BEGIN = 207, END = 209 };
        };
        struct MsgconversationParticipantRingRequest {
                ParticipantRef objectID;
                Sid::String    identityToUse;
                bool           videoCall;
                uint           nrofRedials;
                uint           redialPeriod;
                bool           autoStartVM;
                Sid::String    origin;
                enum { BEGIN = 209, END = 216 };
        };
        struct MsgconversationParticipantRingItRequest {
                ParticipantRef objectID;
                enum { BEGIN = 216, END = 217 };
        };
        struct MsgconversationParticipantSetLiveIdentityToUseRequest {
                ParticipantRef objectID;
                Sid::String    identityToUse;
                enum { BEGIN = 217, END = 219 };
        };
        struct MsgconversationParticipantGetVideoRequest {
                ParticipantRef objectID;
                enum { BEGIN = 219, END = 220 };
        };
        struct MsgconversationParticipantGetVideoResponse {
                VideoRef video;
                enum { BEGIN = 220, END = 221 };
        };
        struct MsgconversationParticipantHangupRequest {
                ParticipantRef objectID;
                enum { BEGIN = 221, END = 222 };
        };
        struct MsgconversationParticipantRetireRequest {
                ParticipantRef objectID;
                enum { BEGIN = 222, END = 223 };
        };
        struct MsgconversationParticipantOnIncomingDTMF {
                ParticipantRef objectID;
                int            dtmf;
                enum { BEGIN = 223, END = 225 };
        };
        struct MsgconversationParticipant {
                ConversationRef convo_id;
                Sid::String     identity;
                int             rank;
                int             requested_rank;
                int             text_status;
                int             voice_status;
                int             video_status;
                Sid::String     live_price_for_me;
                uint            live_start_timestamp;
                uint            sound_level;
                Sid::String     debuginfo;
                Sid::String     live_identity;
                Sid::String     last_voice_error;
                Sid::String     live_fwd_identities;
                Sid::String     quality_problems;
                int             live_type;
                Sid::String     live_country;
                Sid::String     transferred_by;
                Sid::String     transferred_to;
                Sid::String     adder;
                Sid::List_uint cachedProps;
                enum { BEGIN = 225, END = 245 };
        };
        struct MsgconversationConversationSetOptionRequest {
                ConversationRef objectID;
                int             propKey;
                uint            value;
                enum { BEGIN = 245, END = 248 };
        };
        struct MsgconversationConversationSetTopicRequest {
                ConversationRef objectID;
                Sid::String     topic;
                bool            isXML;
                enum { BEGIN = 248, END = 251 };
        };
        struct MsgconversationConversationSetGuidelinesRequest {
                ConversationRef objectID;
                Sid::String     guidelines;
                bool            isXML;
                enum { BEGIN = 251, END = 254 };
        };
        struct MsgconversationConversationSetPictureRequest {
                ConversationRef objectID;
                Sid::Binary     jpeg;
                enum { BEGIN = 254, END = 256 };
        };
        struct MsgconversationConversationSpawnConferenceRequest {
                ConversationRef  objectID;
                Sid::List_String identitiesToAdd;
                enum { BEGIN = 256, END = 259 };
        };
        struct MsgconversationConversationSpawnConferenceResponse {
                ConversationRef conference;
                enum { BEGIN = 259, END = 260 };
        };
        struct MsgconversationConversationAddConsumersRequest {
                ConversationRef  objectID;
                Sid::List_String identities;
                enum { BEGIN = 260, END = 263 };
        };
        struct MsgconversationConversationAssimilateRequest {                ConversationRef objectID;
                ConversationRef otherConversation;
                enum { BEGIN = 263, END = 265 };
        };
        struct MsgconversationConversationAssimilateResponse {
                ConversationRef conversation;
                enum { BEGIN = 265, END = 266 };
        };
        struct MsgconversationConversationJoinLiveSessionRequest {
                ConversationRef objectID;
                Sid::String     accessToken;
                enum { BEGIN = 266, END = 268 };
        };
        struct MsgconversationConversationRingOthersRequest {
                ConversationRef  objectID;
                Sid::List_String identities;
                bool             videoCall;
                Sid::String      origin;
                enum { BEGIN = 268, END = 273 };
        };
        struct MsgconversationConversationMuteMyMicrophoneRequest {
                ConversationRef objectID;
                enum { BEGIN = 273, END = 274 };
        };
        struct MsgconversationConversationUnmuteMyMicrophoneRequest {
                ConversationRef objectID;
                enum { BEGIN = 274, END = 275 };
        };
        struct MsgconversationConversationHoldMyLiveSessionRequest {
                ConversationRef objectID;
                enum { BEGIN = 275, END = 276 };
        };
        struct MsgconversationConversationResumeMyLiveSessionRequest {
                ConversationRef objectID;
                enum { BEGIN = 276, END = 277 };
        };
        struct MsgconversationConversationLeaveLiveSessionRequest {
                ConversationRef objectID;
                bool            postVoiceAutoresponse;
                enum { BEGIN = 277, END = 279 };
        };
        struct MsgconversationConversationStartVoiceMessageRequest {
                ConversationRef objectID;
                enum { BEGIN = 279, END = 280 };
        };
        struct MsgconversationConversationTransferLiveSessionRequest {
                ConversationRef  objectID;
                Sid::List_String identities;
                Sid::String      transferTopic;
                enum { BEGIN = 280, END = 284 };
        };
        struct MsgconversationConversationCanTransferLiveSessionRequest {
                ConversationRef objectID;
                Sid::String     identity;
                enum { BEGIN = 284, END = 286 };
        };
        struct MsgconversationConversationCanTransferLiveSessionResponse {
                bool result;
                enum { BEGIN = 286, END = 287 };
        };
        struct MsgconversationConversationSendDTMFRequest {
                ConversationRef objectID;
                int             dtmf;
                uint            lengthInMS;
                enum { BEGIN = 287, END = 290 };
        };
        struct MsgconversationConversationStopSendDTMFRequest {
                ConversationRef objectID;
                enum { BEGIN = 290, END = 291 };
        };
        struct MsgconversationConversationSetMyTextStatusToRequest {
                ConversationRef objectID;
                int             status;
                enum { BEGIN = 291, END = 293 };
        };
        struct MsgconversationConversationPostTextRequest {
                ConversationRef objectID;
                Sid::String     text;
                bool            isXML;
                enum { BEGIN = 293, END = 296 };
        };
        struct MsgconversationConversationPostTextResponse {
                MessageRef message;
                enum { BEGIN = 296, END = 297 };
        };
        struct MsgconversationConversationPostContactsRequest {
                ConversationRef objectID;
                ContactRefs     contacts;
                enum { BEGIN = 297, END = 300 };
        };
        struct MsgconversationConversationPostFilesRequest {
                ConversationRef    objectID;
                Sid::List_Filename paths;
                Sid::String        body;
                enum { BEGIN = 300, END = 304 };
        };
        struct MsgconversationConversationPostFilesResponse {
                int           error_code;
                Sid::Filename error_file;
                enum { BEGIN = 304, END = 306 };
        };
        struct MsgconversationConversationPostVoiceMessageRequest {
                ConversationRef objectID;
                VoicemailRef    voicemail;
                Sid::String     body;
                enum { BEGIN = 306, END = 309 };
        };
        struct MsgconversationConversationPostSMSRequest {
                ConversationRef objectID;
                SmsRef          sms;
                Sid::String     body;
                enum { BEGIN = 309, END = 312 };
        };
        struct MsgconversationConversationGetJoinBlobRequest {
                ConversationRef objectID;
                enum { BEGIN = 312, END = 313 };
        };
        struct MsgconversationConversationGetJoinBlobResponse {
                Sid::String blob;
                enum { BEGIN = 313, END = 314 };
        };
        struct MsgconversationConversationJoinRequest {
                ConversationRef objectID;
                enum { BEGIN = 314, END = 315 };
        };
        struct MsgconversationConversationEnterPasswordRequest {
                ConversationRef objectID;
                Sid::String     password;
                enum { BEGIN = 315, END = 317 };
        };
        struct MsgconversationConversationSetPasswordRequest {
                ConversationRef objectID;
                Sid::String     password;
                Sid::String     hint;
                enum { BEGIN = 317, END = 320 };
        };
        struct MsgconversationConversationRetireFromRequest {
                ConversationRef objectID;
                enum { BEGIN = 320, END = 321 };
        };
        struct MsgconversationConversationDeleteRequest {
                ConversationRef objectID;
                enum { BEGIN = 321, END = 322 };
        };
        struct MsgconversationConversationRenameToRequest {
                ConversationRef objectID;
                Sid::String     name;
                enum { BEGIN = 322, END = 324 };
        };
        struct MsgconversationConversationSetBookmarkRequest {
                ConversationRef objectID;
                bool            bookmark;
                enum { BEGIN = 324, END = 326 };
        };
        struct MsgconversationConversationSetAlertStringRequest {
                ConversationRef objectID;
                Sid::String     alertString;
                enum { BEGIN = 326, END = 328 };
        };
        struct MsgconversationConversationRemoveFromInboxRequest {
                ConversationRef objectID;
                enum { BEGIN = 328, END = 329 };
        };
        struct MsgconversationConversationAddToInboxRequest {
                ConversationRef objectID;
                uint            timestamp;
                enum { BEGIN = 329, END = 331 };
        };
        struct MsgconversationConversationSetConsumedHorizonRequest {
                ConversationRef objectID;
                uint            timestamp;
                bool            also_unconsume;
                enum { BEGIN = 331, END = 334 };
        };
        struct MsgconversationConversationMarkUnreadRequest {
                ConversationRef objectID;
                enum { BEGIN = 334, END = 335 };
        };
        struct MsgconversationConversationIsMemberOfRequest {
                ConversationRef objectID;
                ContactGroupRef group;
                enum { BEGIN = 335, END = 337 };
        };
        struct MsgconversationConversationIsMemberOfResponse {
                bool result;
                enum { BEGIN = 337, END = 338 };
        };
        struct MsgconversationConversationGetParticipantsRequest {
                ConversationRef objectID;
                int             filter;
                enum { BEGIN = 338, END = 340 };
        };
        struct MsgconversationConversationGetParticipantsResponse {
                ParticipantRefs participants;
                enum { BEGIN = 340, END = 342 };
        };
        struct MsgconversationConversationGetLastMessagesRequest {                ConversationRef objectID;
                uint            requireTimestamp;
                enum { BEGIN = 342, END = 344 };
        };
        struct MsgconversationConversationGetLastMessagesResponse {
                MessageRefs contextMessages;
                MessageRefs unconsumedMessages;
                enum { BEGIN = 344, END = 348 };
        };
        struct MsgconversationConversationFindMessageRequest {
                ConversationRef objectID;
                Sid::String     text;
                uint            fromTimestampUp;
                enum { BEGIN = 348, END = 351 };
        };
        struct MsgconversationConversationFindMessageResponse {
                MessageRef message;
                enum { BEGIN = 351, END = 352 };
        };
        struct MsgconversationConversationOnParticipantListChange {
                ConversationRef objectID;
                enum { BEGIN = 352, END = 353 };
        };
        struct MsgconversationConversationOnMessage {
                ConversationRef objectID;
                MessageRef      message;
                enum { BEGIN = 353, END = 355 };
        };
        struct MsgconversationConversationOnSpawnConference {
                ConversationRef objectID;
                ConversationRef spawned;
                enum { BEGIN = 355, END = 357 };
        };
        struct MsgconversationConversation {
                int             type;
                Sid::String     creator;
                uint            creation_timestamp;
                int             opt_entry_level_rank;
                bool            opt_disclose_history;
                int             opt_admin_only_activities;
                Sid::String     meta_name;
                Sid::String     meta_topic;
                Sid::String     meta_guidelines;
                Sid::Binary     meta_picture;
                ConversationRef spawned_from_convo_id;
                Sid::String     live_host;
                int             my_status;
                Sid::String     alert_string;
                bool            is_bookmarked;
                bool            opt_joining_enabled;
                Sid::String     displayname;
                Sid::String     given_displayname;
                int             local_livestatus;
                uint            inbox_timestamp;
                bool            unconsumed_messages_voice;
                VoicemailRef    active_vm_id;
                Sid::String     identity;
                MessageRef      inbox_message_id;
                uint            live_start_timestamp;
                uint            unconsumed_suppressed_messages;
                uint            unconsumed_normal_messages;
                uint            unconsumed_elevated_messages;
                uint            consumption_horizon;
                Sid::String     passwordhint;
                uint            last_activity_timestamp;
                bool            live_is_muted;
                Sid::List_uint cachedProps;
                enum { BEGIN = 357, END = 389 };
        };
        struct MsgconversationCreateConferenceResponse {
                ConversationRef conference;
                enum { BEGIN = 389, END = 390 };
        };
        struct MsgconversationGetConversationByIdentityRequest {
                Sid::String convoIdentity;
                enum { BEGIN = 390, END = 391 };
        };
        struct MsgconversationGetConversationByIdentityResponse {
                ConversationRef conversation;
                enum { BEGIN = 391, END = 392 };
        };
        struct MsgconversationGetConversationByParticipantsRequest {
                Sid::List_String participantIdentities;
                bool             createIfNonExisting;
                bool             ignoreBookmarkedOrNamed;
                enum { BEGIN = 392, END = 396 };
        };
        struct MsgconversationGetConversationByParticipantsResponse {
                ConversationRef conversation;
                enum { BEGIN = 396, END = 397 };
        };
        struct MsgconversationGetConversationByBlobRequest {
                Sid::String joinBlob;
                bool        alsoJoin;
                enum { BEGIN = 397, END = 399 };
        };
        struct MsgconversationGetConversationByBlobResponse {
                ConversationRef conversation;
                enum { BEGIN = 399, END = 400 };
        };
        struct MsgconversationGetConversationListRequest {
                int type;
                enum { BEGIN = 400, END = 401 };
        };
        struct MsgconversationGetConversationListResponse {
                ConversationRefs conversations;
                enum { BEGIN = 401, END = 403 };
        };
        struct MsgconversationOnConversationListChange {
                ConversationRef conversation;
                int             type;
                bool            added;
                enum { BEGIN = 403, END = 406 };
        };
        struct MsgconversationMessageCanEditRequest {
                MessageRef objectID;
                enum { BEGIN = 406, END = 407 };
        };
        struct MsgconversationMessageCanEditResponse {
                bool result;
                enum { BEGIN = 407, END = 408 };
        };
        struct MsgconversationMessageEditRequest {
                MessageRef  objectID;
                Sid::String newText;
                bool        isXML;
                enum { BEGIN = 408, END = 411 };
        };
        struct MsgconversationMessageGetContactsRequest {
                MessageRef objectID;
                enum { BEGIN = 411, END = 412 };
        };
        struct MsgconversationMessageGetContactsResponse {
                ContactRefs contacts;
                enum { BEGIN = 412, END = 414 };
        };
        struct MsgconversationMessageGetTransfersRequest {
                MessageRef objectID;
                enum { BEGIN = 414, END = 415 };
        };
        struct MsgconversationMessageGetTransfersResponse {
                TransferRefs transfers;
                enum { BEGIN = 415, END = 417 };
        };
        struct MsgconversationMessageGetVoiceMessageRequest {
                MessageRef objectID;
                enum { BEGIN = 417, END = 418 };
        };
        struct MsgconversationMessageGetVoiceMessageResponse {
                VoicemailRef voicemail;
                enum { BEGIN = 418, END = 419 };
        };
        struct MsgconversationMessageGetSMSRequest {
                MessageRef objectID;
                enum { BEGIN = 419, END = 420 };
        };
        struct MsgconversationMessageGetSMSResponse {
                SmsRef sms;
                enum { BEGIN = 420, END = 421 };
        };
        struct MsgconversationMessageDeleteLocallyRequest {
                MessageRef objectID;
                enum { BEGIN = 421, END = 422 };
        };
        struct MsgconversationMessage {
                Sid::String     convo_guid;
                uint            timestamp;
                Sid::String     author;
                Sid::String     author_displayname;
                Sid::String     identities;
                int             leavereason;
                Sid::String     body_xml;
                Sid::String     edited_by;
                uint            edit_timestamp;
                Sid::String     originally_meant_for;
                Sid::Binary     guid;
                ConversationRef convo_id;
                int             type;
                int             sending_status;
                uint            param_key;
                uint            param_value;
                Sid::String     reason;
                int             consumption_status;
                uint            participant_count;
                Sid::List_uint cachedProps;
                enum { BEGIN = 422, END = 441 };
        };
        struct MsgconversationGetMessageByGuidRequest {
                Sid::Binary guid;
                enum { BEGIN = 441, END = 442 };
        };
        struct MsgconversationGetMessageByGuidResponse {
                MessageRef message;
                enum { BEGIN = 442, END = 443 };        };
        struct MsgconversationOnMessage {
                MessageRef      message;
                bool            changesInboxTimestamp;
                MessageRef      supersedesHistoryMessage;
                ConversationRef conversation;
                enum { BEGIN = 443, END = 447 };
        };
        struct MsgvideoVideoSetScreenRequest {
                VideoRef objectID;
                uint     windowh;
                enum { BEGIN = 447, END = 449 };
        };
        struct MsgvideoVideoStartRequest {
                VideoRef objectID;
                enum { BEGIN = 449, END = 450 };
        };
        struct MsgvideoVideoStopRequest {
                VideoRef objectID;
                enum { BEGIN = 450, END = 451 };
        };
        struct MsgvideoVideoSubmitCaptureRequestRequest {
                VideoRef objectID;
                enum { BEGIN = 451, END = 452 };
        };
        struct MsgvideoVideoSubmitCaptureRequestResponse {
                bool ret;
                uint requestId;
                enum { BEGIN = 452, END = 454 };
        };
        struct MsgvideoVideoOnCaptureRequestCompleted {
                VideoRef    objectID;
                uint        requestId;
                bool        isSuccessful;
                Sid::Binary image;
                int         width;
                int         height;
                enum { BEGIN = 454, END = 460 };
        };
        struct MsgvideoVideoSetScreenCaptureRectangleRequest {
                VideoRef objectID;
                int      x0;
                int      y0;
                uint     width;
                uint     height;
                int      monitorNumber;
                uint     windowHandle;
                enum { BEGIN = 460, END = 467 };
        };
        struct MsgvideoVideoSetRenderRectangleRequest {
                VideoRef objectID;
                int      x0;
                int      y0;
                uint     width;
                uint     height;
                enum { BEGIN = 467, END = 472 };
        };
        struct MsgvideoVideoSelectVideoSourceRequest {
                VideoRef    objectID;
                int         mediaType;
                Sid::String webcamName;
                Sid::String devicePath;
                bool        updateSetup;
                enum { BEGIN = 472, END = 477 };
        };
        struct MsgvideoVideoGetCurrentVideoDeviceRequest {
                VideoRef objectID;
                enum { BEGIN = 477, END = 478 };
        };
        struct MsgvideoVideoGetCurrentVideoDeviceResponse {
                int         mediatype;
                Sid::String deviceName;
                Sid::String devicePath;
                enum { BEGIN = 478, END = 481 };
        };
        struct MsgvideoVideoOnLastFrameCapture {
                VideoRef    objectID;
                Sid::Binary image;
                uint        width;
                uint        height;
                enum { BEGIN = 481, END = 485 };
        };
        struct MsgvideoVideo {
                int         status;
                Sid::String error;
                Sid::String debuginfo;
                Sid::String dimensions;
                int         media_type;
                uint        convo_id;
                Sid::String device_path;
                Sid::List_uint cachedProps;
                enum { BEGIN = 485, END = 492 };
        };
        struct MsgvideoGetAvailableVideoDevicesResponse {
                Sid::List_String deviceNames;
                Sid::List_String devicePaths;
                uint             count;
                enum { BEGIN = 492, END = 497 };
        };
        struct MsgvideoHasVideoDeviceCapabilityRequest {
                Sid::String deviceName;
                Sid::String devicePath;
                int         cap;
                enum { BEGIN = 497, END = 500 };
        };
        struct MsgvideoDisplayVideoDeviceTuningDialogRequest {
                Sid::String deviceName;
                Sid::String devicePath;
                enum { BEGIN = 500, END = 502 };
        };
        struct MsgvideoGetPreviewVideoRequest {
                int         type;
                Sid::String deviceName;
                Sid::String devicePath;
                enum { BEGIN = 502, END = 505 };
        };
        struct MsgvideoGetPreviewVideoResponse {
                VideoRef video;
                enum { BEGIN = 505, END = 506 };
        };
        struct MsgvideoVideoCommandRequest {
                Sid::String command;
                enum { BEGIN = 506, END = 507 };
        };
        struct MsgvideoVideoCommandResponse {
                Sid::String response;
                enum { BEGIN = 507, END = 508 };
        };
        struct MsgvmVoicemailStartRecordingRequest {
                VoicemailRef objectID;
                enum { BEGIN = 508, END = 509 };
        };
        struct MsgvmVoicemailStopRecordingRequest {
                VoicemailRef objectID;
                enum { BEGIN = 509, END = 510 };
        };
        struct MsgvmVoicemailStartPlaybackRequest {
                VoicemailRef objectID;
                enum { BEGIN = 510, END = 511 };
        };
        struct MsgvmVoicemailStopPlaybackRequest {
                VoicemailRef objectID;
                enum { BEGIN = 511, END = 512 };
        };
        struct MsgvmVoicemailDeleteRequest {
                VoicemailRef objectID;
                enum { BEGIN = 512, END = 513 };
        };
        struct MsgvmVoicemailCancelRequest {
                VoicemailRef objectID;
                enum { BEGIN = 513, END = 514 };
        };
        struct MsgvmVoicemailCheckPermissionRequest {
                VoicemailRef objectID;
                enum { BEGIN = 514, END = 515 };
        };
        struct MsgvmVoicemailCheckPermissionResponse {
                bool result;
                enum { BEGIN = 515, END = 516 };
        };
        struct MsgvmVoicemail {
                int             type;
                Sid::String     partner_handle;
                Sid::String     partner_dispname;
                int             status;
                int             failurereason;
                Sid::String     subject;
                uint            timestamp;
                uint            duration;
                uint            allowed_duration;
                uint            playback_progress;
                ConversationRef convo_id;
                Sid::Binary     chatmsg_guid;
                Sid::List_uint cachedProps;
                enum { BEGIN = 516, END = 528 };
        };
        struct MsgvmGetGreetingRequest {
                Sid::String skypeName;
                enum { BEGIN = 528, END = 529 };
        };
        struct MsgvmGetGreetingResponse {
                VoicemailRef greeting;
                enum { BEGIN = 529, END = 530 };
        };
        struct MsgaudioPlayStartRequest {
                uint        soundid;
                Sid::Binary sound;
                bool        loop;
                bool        useCallOutDevice;
                enum { BEGIN = 530, END = 534 };
        };
        struct MsgaudioPlayStartFromFileRequest {
                uint          soundid;
                Sid::Filename datafile;
                bool          loop;
                bool          useCallOutDevice;
                enum { BEGIN = 534, END = 538 };
        };
        struct MsgaudioPlayStartFromFileResponse {
                int result;
                enum { BEGIN = 538, END = 539 };
        };
        struct MsgaudioPlayStopRequest {
                uint soundid;
                enum { BEGIN = 539, END = 540 };
        };
        struct MsgaudioStartRecordingTestRequest {
                bool recordAndPlaybackData;
                enum { BEGIN = 540, END = 541 };
        };
        struct MsgaudioGetAvailableOutputDevicesResponse {
                Sid::List_String handleList;
                Sid::List_String nameList;
                Sid::List_String productIdList;
                enum { BEGIN = 541, END = 547 };
        };
        struct MsgaudioGetAvailableRecordingDevicesResponse {
                Sid::List_String handleList;                Sid::List_String nameList;
                Sid::List_String productIdList;
                enum { BEGIN = 547, END = 553 };
        };
        struct MsgaudioSelectSoundDevicesRequest {
                Sid::String callInDevice;
                Sid::String callOutDevice;
                Sid::String waveOutDevice;
                enum { BEGIN = 553, END = 556 };
        };
        struct MsgaudioGetAudioDeviceCapabilitiesRequest {
                Sid::String deviceHandle;
                enum { BEGIN = 556, END = 557 };
        };
        struct MsgaudioGetAudioDeviceCapabilitiesResponse {
                Sid::String interfaceString;
                uint        capabilities;
                enum { BEGIN = 557, END = 559 };
        };
        struct MsgaudioGetNrgLevelsResponse {
                uint micLevel;
                uint speakerLevel;
                enum { BEGIN = 559, END = 561 };
        };
        struct MsgaudioVoiceCommandRequest {
                Sid::String command;
                enum { BEGIN = 561, END = 562 };
        };
        struct MsgaudioVoiceCommandResponse {
                Sid::String response;
                enum { BEGIN = 562, END = 563 };
        };
        struct MsgaudioGetSpeakerVolumeResponse {
                uint volume;
                enum { BEGIN = 563, END = 564 };
        };
        struct MsgaudioSetSpeakerVolumeRequest {
                uint volume;
                enum { BEGIN = 564, END = 565 };
        };
        struct MsgaudioGetMicVolumeResponse {
                uint micVolume;
                enum { BEGIN = 565, END = 566 };
        };
        struct MsgaudioSetMicVolumeRequest {
                uint volume;
                enum { BEGIN = 566, END = 567 };
        };
        struct MsgaudioIsSpeakerMutedResponse {
                bool muted;
                enum { BEGIN = 567, END = 568 };
        };
        struct MsgaudioIsMicrophoneMutedResponse {
                bool muted;
                enum { BEGIN = 568, END = 569 };
        };
        struct MsgaudioMuteSpeakersRequest {
                bool mute;
                enum { BEGIN = 569, END = 570 };
        };
        struct MsgaudioMuteMicrophoneRequest {
                bool mute;
                enum { BEGIN = 570, END = 571 };
        };
        struct MsgbwmSetOperatingMediaRequest {
                int  media;
                uint maxUplinkBps;
                uint maxDownlinkBps;
                enum { BEGIN = 571, END = 574 };
        };
        struct MsgsmsSmsGetTargetStatusRequest {
                SmsRef      objectID;
                Sid::String target;
                enum { BEGIN = 574, END = 576 };
        };
        struct MsgsmsSmsGetTargetStatusResponse {
                int status;
                enum { BEGIN = 576, END = 577 };
        };
        struct MsgsmsSmsGetTargetPriceRequest {
                SmsRef      objectID;
                Sid::String target;
                enum { BEGIN = 577, END = 579 };
        };
        struct MsgsmsSmsGetTargetPriceResponse {
                uint price;
                enum { BEGIN = 579, END = 580 };
        };
        struct MsgsmsSmsSetTargetsRequest {
                SmsRef           objectID;
                Sid::List_String numbers;
                enum { BEGIN = 580, END = 583 };
        };
        struct MsgsmsSmsSetTargetsResponse {
                bool success;
                enum { BEGIN = 583, END = 584 };
        };
        struct MsgsmsSmsSetBodyRequest {
                SmsRef      objectID;
                Sid::String text;
                enum { BEGIN = 584, END = 586 };
        };
        struct MsgsmsSmsSetBodyResponse {
                int              result;
                Sid::List_String chunks;
                uint             charsUntilNextChunk;
                enum { BEGIN = 586, END = 590 };
        };
        struct MsgsmsSmsGetBodyChunksRequest {
                SmsRef objectID;
                enum { BEGIN = 590, END = 591 };
        };
        struct MsgsmsSmsGetBodyChunksResponse {
                Sid::List_String textChunks;
                uint             charsUntilNextChunk;
                enum { BEGIN = 591, END = 594 };
        };
        struct MsgsmsSms {
                bool        is_failed_unseen;
                uint        price_precision;
                int         type;
                int         status;
                int         failurereason;
                uint        price;
                Sid::String price_currency;
                Sid::String target_numbers;
                Sid::Binary target_statuses;
                Sid::String body;
                uint        timestamp;
                Sid::String reply_to_number;
                MessageRef  chatmsg_id;
                Sid::List_uint cachedProps;
                enum { BEGIN = 594, END = 607 };
        };
        struct MsgsmsRequestConfirmationCodeRequest {
                int         type;
                Sid::String number;
                enum { BEGIN = 607, END = 609 };
        };
        struct MsgsmsRequestConfirmationCodeResponse {
                SmsRef sms;
                enum { BEGIN = 609, END = 610 };
        };
        struct MsgsmsSubmitConfirmationCodeRequest {
                Sid::String number;
                Sid::String code;
                enum { BEGIN = 610, END = 612 };
        };
        struct MsgsmsSubmitConfirmationCodeResponse {
                SmsRef sms;
                enum { BEGIN = 612, END = 613 };
        };
        struct MsgsmsCreateOutgoingSmsResponse {
                SmsRef sms;
                enum { BEGIN = 613, END = 614 };
        };
        struct MsgftTransferAcceptRequest {
                TransferRef   objectID;
                Sid::Filename filenameWithPath;
                enum { BEGIN = 614, END = 616 };
        };
        struct MsgftTransferAcceptResponse {
                bool success;
                enum { BEGIN = 616, END = 617 };
        };
        struct MsgftTransferPauseRequest {
                TransferRef objectID;
                enum { BEGIN = 617, END = 618 };
        };
        struct MsgftTransferResumeRequest {
                TransferRef objectID;
                enum { BEGIN = 618, END = 619 };
        };
        struct MsgftTransferCancelRequest {
                TransferRef objectID;
                enum { BEGIN = 619, END = 620 };
        };
        struct MsgftTransfer {
                int             type;
                Sid::String     partner_handle;
                Sid::String     partner_dispname;
                int             status;
                int             failurereason;
                uint            starttime;
                uint            finishtime;
                Sid::String     filepath;
                Sid::String     filename;
                Sid::String     filesize;
                Sid::String     bytestransferred;
                uint            bytespersecond;
                Sid::Binary     chatmsg_guid;
                uint            chatmsg_index;
                ConversationRef convo_id;
                Sid::List_uint cachedProps;
                enum { BEGIN = 620, END = 635 };
        };
        struct MsgaccountAccountGetStatusWithProgressRequest {
                AccountRef objectID;
                enum { BEGIN = 635, END = 636 };
        };
        struct MsgaccountAccountGetStatusWithProgressResponse {
                int  status;
                uint progress;
                enum { BEGIN = 636, END = 638 };
        };
        struct MsgaccountAccountLoginRequest {
                AccountRef objectID;
                int        setAvailabilityTo;
                enum { BEGIN = 638, END = 640 };
        };
        struct MsgaccountAccountLoginWithPasswordRequest {
                AccountRef  objectID;
                Sid::String password;
                bool        savePwd;
                bool        saveDataLocally;
                enum { BEGIN = 640, END = 644 };
        };
        struct MsgaccountAccountRegisterRequest {
                AccountRef  objectID;
                Sid::String password;
                bool        savePwd;                bool        saveDataLocally;
                Sid::String email;
                bool        allowSpam;
                enum { BEGIN = 644, END = 650 };
        };
        struct MsgaccountAccountLogoutRequest {
                AccountRef objectID;
                bool       clearSavedPwd;
                enum { BEGIN = 650, END = 652 };
        };
        struct MsgaccountAccountChangePasswordRequest {
                AccountRef  objectID;
                Sid::String oldPassword;
                Sid::String newPassword;
                bool        savePwd;
                enum { BEGIN = 652, END = 656 };
        };
        struct MsgaccountAccountSetPasswordSavedRequest {
                AccountRef objectID;
                bool       savePwd;
                enum { BEGIN = 656, END = 658 };
        };
        struct MsgaccountAccountSetServersideIntPropertyRequest {
                AccountRef objectID;
                int        propKey;
                uint       value;
                enum { BEGIN = 658, END = 661 };
        };
        struct MsgaccountAccountSetServersideStrPropertyRequest {
                AccountRef  objectID;
                int         propKey;
                Sid::String value;
                enum { BEGIN = 661, END = 664 };
        };
        struct MsgaccountAccountCancelServerCommitRequest {
                AccountRef objectID;
                enum { BEGIN = 664, END = 665 };
        };
        struct MsgaccountAccountSetIntPropertyRequest {
                AccountRef objectID;
                int        propKey;
                uint       value;
                enum { BEGIN = 665, END = 668 };
        };
        struct MsgaccountAccountSetStrPropertyRequest {
                AccountRef  objectID;
                int         propKey;
                Sid::String value;
                enum { BEGIN = 668, END = 671 };
        };
        struct MsgaccountAccountSetBinPropertyRequest {
                AccountRef  objectID;
                int         propKey;
                Sid::Binary value;
                enum { BEGIN = 671, END = 674 };
        };
        struct MsgaccountAccountSetAvailabilityRequest {
                AccountRef objectID;
                int        availability;
                enum { BEGIN = 674, END = 676 };
        };
        struct MsgaccountAccountSetStandbyRequest {
                AccountRef objectID;
                bool       standby;
                enum { BEGIN = 676, END = 678 };
        };
        struct MsgaccountAccountGetCapabilityStatusRequest {
                AccountRef objectID;
                int        capability;
                enum { BEGIN = 678, END = 680 };
        };
        struct MsgaccountAccountGetCapabilityStatusResponse {
                int  status;
                uint expiryTimestamp;
                enum { BEGIN = 680, END = 682 };
        };
        struct MsgaccountAccountGetSkypenameHashRequest {
                AccountRef objectID;
                enum { BEGIN = 682, END = 683 };
        };
        struct MsgaccountAccountGetSkypenameHashResponse {
                Sid::String skypenameHash;
                enum { BEGIN = 683, END = 684 };
        };
        struct MsgaccountAccountGetVerifiedEmailRequest {
                AccountRef objectID;
                enum { BEGIN = 684, END = 685 };
        };
        struct MsgaccountAccountGetVerifiedEmailResponse {
                Sid::String email;
                enum { BEGIN = 685, END = 686 };
        };
        struct MsgaccountAccountGetVerifiedCompanyRequest {
                AccountRef objectID;
                enum { BEGIN = 686, END = 687 };
        };
        struct MsgaccountAccountGetVerifiedCompanyResponse {
                Sid::String company;
                enum { BEGIN = 687, END = 688 };
        };
        struct MsgaccountAccountDeleteRequest {
                AccountRef objectID;
                enum { BEGIN = 688, END = 689 };
        };
        struct MsgaccountAccount {
                Sid::String skypename;
                Sid::String fullname;
                uint        birthday;
                uint        gender;
                Sid::String languages;
                Sid::String country;
                Sid::String province;
                Sid::String city;
                Sid::String phone_home;
                Sid::String phone_office;
                Sid::String phone_mobile;
                Sid::String emails;
                Sid::String homepage;
                Sid::String about;
                uint        profile_timestamp;
                Sid::String mood_text;
                uint        timezone;
                uint        nrof_authed_buddies;
                int         availability;
                Sid::Binary avatar_image;
                int         status;
                int         pwdchangestatus;
                Sid::String suggested_skypename;
                int         logoutreason;
                Sid::String skypeout_balance_currency;
                uint        skypeout_balance;
                Sid::String skypein_numbers;
                Sid::String offline_callforward;
                int         commitstatus;
                int         cblsyncstatus;
                int         chat_policy;
                int         skype_call_policy;
                int         pstn_call_policy;
                int         avatar_policy;
                int         buddycount_policy;
                int         timezone_policy;
                int         webpresence_policy;
                int         phonenumbers_policy;
                int         voicemail_policy;
                uint        avatar_timestamp;
                uint        mood_timestamp;
                Sid::String rich_mood_text;
                Sid::String partner_optedout;
                Sid::String service_provider_info;
                uint        registration_timestamp;
                uint        nr_of_other_instances;
                uint        skypeout_precision;
                Sid::List_uint cachedProps;
                enum { BEGIN = 689, END = 736 };
        };
        struct MsgaccountGetAccountRequest {
                Sid::String identity;
                enum { BEGIN = 736, END = 737 };
        };
        struct MsgaccountGetAccountResponse {
                AccountRef account;
                enum { BEGIN = 737, END = 738 };
        };
        struct MsgaccountGetExistingAccountsResponse {
                Sid::List_String accountNameList;
                enum { BEGIN = 738, END = 740 };
        };
        struct MsgaccountGetDefaultAccountNameResponse {
                Sid::String account;
                enum { BEGIN = 740, END = 741 };
        };
        struct MsgaccountGetSuggestedSkypenameRequest {
                Sid::String fullname;
                enum { BEGIN = 741, END = 742 };
        };
        struct MsgaccountGetSuggestedSkypenameResponse {
                Sid::String suggestedName;
                enum { BEGIN = 742, END = 743 };
        };
        struct MsgaccountValidateAvatarRequest {
                Sid::Binary value;
                enum { BEGIN = 743, END = 744 };
        };
        struct MsgaccountValidateAvatarResponse {
                int result;
                int freeBytesLeft;
                enum { BEGIN = 744, END = 746 };
        };
        struct MsgaccountValidateProfileStringRequest {
                int         propKey;
                Sid::String strValue;
                bool        forRegistration;
                enum { BEGIN = 746, END = 749 };
        };
        struct MsgaccountValidateProfileStringResponse {
                int result;
                int freeBytesLeft;
                enum { BEGIN = 749, END = 751 };
        };
        struct MsgaccountValidatePasswordRequest {
                Sid::String username;
                Sid::String password;
                enum { BEGIN = 751, END = 753 };
        };
        struct MsgaccountValidatePasswordResponse {
                int result;
                enum { BEGIN = 753, END = 754 };
        };
        struct MsgconnectionOnProxyAuthFailure {
                int type;                enum { BEGIN = 754, END = 755 };
        };
        struct MsgconnectionGetUsedPortResponse {
                uint port;
                enum { BEGIN = 755, END = 756 };
        };
        struct MsgsetupGetStrRequest {
                Sid::String key;
                enum { BEGIN = 756, END = 757 };
        };
        struct MsgsetupGetStrResponse {
                Sid::String value;
                enum { BEGIN = 757, END = 758 };
        };
        struct MsgsetupGetIntRequest {
                Sid::String key;
                enum { BEGIN = 758, END = 759 };
        };
        struct MsgsetupGetIntResponse {
                int value;
                enum { BEGIN = 759, END = 760 };
        };
        struct MsgsetupGetBinRequest {
                Sid::String key;
                enum { BEGIN = 760, END = 761 };
        };
        struct MsgsetupGetBinResponse {
                Sid::Binary value;
                enum { BEGIN = 761, END = 762 };
        };
        struct MsgsetupSetStrRequest {
                Sid::String key;
                Sid::String value;
                enum { BEGIN = 762, END = 764 };
        };
        struct MsgsetupSetIntRequest {
                Sid::String key;
                int         value;
                enum { BEGIN = 764, END = 766 };
        };
        struct MsgsetupSetBinRequest {
                Sid::String key;
                Sid::Binary value;
                enum { BEGIN = 766, END = 768 };
        };
        struct MsgsetupIsDefinedRequest {
                Sid::String key;
                enum { BEGIN = 768, END = 769 };
        };
        struct MsgsetupIsDefinedResponse {
                bool value;
                enum { BEGIN = 769, END = 770 };
        };
        struct MsgsetupDeleteRequest {
                Sid::String key;
                enum { BEGIN = 770, END = 771 };
        };
        struct MsgsetupGetSubKeysRequest {
                Sid::String key;
                enum { BEGIN = 771, END = 772 };
        };
        struct MsgsetupGetSubKeysResponse {
                Sid::List_String value;
                enum { BEGIN = 772, END = 774 };
        };
        struct MsgisoGetISOLanguageInfoResponse {
                Sid::List_String languageCodeList;
                Sid::List_String languageNameList;
                enum { BEGIN = 774, END = 778 };
        };
        struct MsgisoGetISOCountryInfoResponse {
                Sid::List_String countryCodeList;
                Sid::List_String countryNameList;
                Sid::List_uint   countryPrefixList;
                Sid::List_String countryDialExampleList;
                enum { BEGIN = 778, END = 786 };
        };
        struct MsgisoGetISOCountryCodebyPhoneNoRequest {
                Sid::String number;
                enum { BEGIN = 786, END = 787 };
        };
        struct MsgisoGetISOCountryCodebyPhoneNoResponse {
                Sid::String countryCode;
                enum { BEGIN = 787, END = 788 };
        };
        struct Msgapp2appApp2AppCreateRequest {
                Sid::String appname;
                enum { BEGIN = 788, END = 789 };
        };
        struct Msgapp2appApp2AppCreateResponse {
                bool result;
                enum { BEGIN = 789, END = 790 };
        };
        struct Msgapp2appApp2AppDeleteRequest {
                Sid::String appname;
                enum { BEGIN = 790, END = 791 };
        };
        struct Msgapp2appApp2AppDeleteResponse {
                bool result;
                enum { BEGIN = 791, END = 792 };
        };
        struct Msgapp2appApp2AppConnectRequest {
                Sid::String appname;
                Sid::String skypename;
                enum { BEGIN = 792, END = 794 };
        };
        struct Msgapp2appApp2AppConnectResponse {
                bool result;
                enum { BEGIN = 794, END = 795 };
        };
        struct Msgapp2appApp2AppDisconnectRequest {
                Sid::String appname;
                Sid::String stream;
                enum { BEGIN = 795, END = 797 };
        };
        struct Msgapp2appApp2AppDisconnectResponse {
                bool result;
                enum { BEGIN = 797, END = 798 };
        };
        struct Msgapp2appApp2AppWriteRequest {
                Sid::String appname;
                Sid::String stream;
                Sid::Binary data;
                enum { BEGIN = 798, END = 801 };
        };
        struct Msgapp2appApp2AppWriteResponse {
                bool result;
                enum { BEGIN = 801, END = 802 };
        };
        struct Msgapp2appApp2AppDatagramRequest {
                Sid::String appname;
                Sid::String stream;
                Sid::Binary data;
                enum { BEGIN = 802, END = 805 };
        };
        struct Msgapp2appApp2AppDatagramResponse {
                bool result;
                enum { BEGIN = 805, END = 806 };
        };
        struct Msgapp2appApp2AppReadRequest {
                Sid::String appname;
                Sid::String stream;
                enum { BEGIN = 806, END = 808 };
        };
        struct Msgapp2appApp2AppReadResponse {
                bool        result;
                Sid::Binary data;
                enum { BEGIN = 808, END = 810 };
        };
        struct Msgapp2appApp2AppGetConnectableUsersRequest {
                Sid::String appname;
                enum { BEGIN = 810, END = 811 };
        };
        struct Msgapp2appApp2AppGetConnectableUsersResponse {
                bool             result;
                Sid::List_String users;
                enum { BEGIN = 811, END = 814 };
        };
        struct Msgapp2appApp2AppGetStreamsListRequest {
                Sid::String appname;
                int         listType;
                enum { BEGIN = 814, END = 816 };
        };
        struct Msgapp2appApp2AppGetStreamsListResponse {
                bool             result;
                Sid::List_String streams;
                Sid::List_uint   receivedSizes;
                enum { BEGIN = 816, END = 821 };
        };
        struct Msgapp2appOnApp2AppDatagram {
                Sid::String appname;
                Sid::String stream;
                Sid::Binary data;
                enum { BEGIN = 821, END = 824 };
        };
        struct Msgapp2appOnApp2AppStreamListChange {
                Sid::String      appname;
                int              listType;
                Sid::List_String streams;
                Sid::List_uint   receivedSizes;
                enum { BEGIN = 824, END = 830 };
        };
#ifdef SE_USE_NAMESPACE
} // skylib
#endif

#endif // __SIDG_MSGS_SKYLIBHPP_INCLUDED____
