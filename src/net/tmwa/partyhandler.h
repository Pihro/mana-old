/*
 *  The Mana Client
 *  Copyright (C) 2008  Lloyd Bryant <lloyd_bryant@netzero.net>
 *  Copyright (C) 2009-2012  The Mana Developers
 *
 *  This file is part of The Mana Client.
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef NET_TA_PARTYHANDLER_H
#define NET_TA_PARTYHANDLER_H

#include "net/net.h"
#include "net/partyhandler.h"

#include "net/tmwa/messagehandler.h"

#include "party.h"

namespace TmwAthena {

class PartyHandler : public MessageHandler, public Net::PartyHandler
{
    public:
        PartyHandler();

        ~PartyHandler();

        void handleMessage(MessageIn &msg);

        void create(const std::string &name = "");

        void join(int partyId);

        void invite(Being *being);

        void invite(const std::string &name);

        void inviteResponse(const std::string &inviter, bool accept);

        void leave();

        void kick(Being *being);

        void kick(const std::string &name);

        void chat(const std::string &text);

        void requestPartyMembers();

        PartyShare getShareExperience() { return mShareExp; }

        void setShareExperience(PartyShare share);

        PartyShare getShareItems() { return mShareItems; }

        void setShareItems(PartyShare share);

    private:
        PartyShare mShareExp, mShareItems;
};

} // namespace TmwAthena

#endif // NET_TA_PARTYHANDLER_H
