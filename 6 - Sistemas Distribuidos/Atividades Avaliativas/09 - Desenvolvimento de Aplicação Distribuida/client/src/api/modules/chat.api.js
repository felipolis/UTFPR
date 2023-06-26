import privateClient from '../client/private.client';

const chatEndpoints = {
	fetchChats: '/chat',
    accessChat: '/chat',
    createGroupChat: '/chat/group',
    renameGroup: '/chat/rename',
    removeFromGroup: '/chat/groupremove',
    addToGroup: '/chat/groupadd',
}

const chatApi = {
    fetchChats: async () => {
        try {
            const response = await privateClient.get(
                chatEndpoints.fetchChats
            );
            return { response };
        } catch (error) {
            console.log(error);
            return { error };
        }
    },

    accessChat: async ({ userId }) => {
        try {
            const response = await privateClient.post(
                chatEndpoints.accessChat, {
                    userId
                }
            );
            return { response };
        } catch (error) {
            console.log(error);
            return { error };
        }
    },

    createGroupChat: async ({ name, users }) => {
        try {
            const response = await privateClient.post(
                chatEndpoints.createGroupChat, {
                    name,
                    users
                }
            );
            return { response };
        } catch (error) {
            console.log(error);
            return { error };
        }
    },

    renameGroup: async ({ chatId, chatName }) => {
        try {
            const response = await privateClient.put(
                chatEndpoints.renameGroup, {
                    chatId,
                    chatName
                }
            );
            return { response };
        } catch (error) {
            console.log(error);
            return { error };
        }
    },

    removeFromGroup: async ({ chatId, userId }) => {
        try {
            const response = await privateClient.put(
                chatEndpoints.removeFromGroup, {
                    chatId,
                    userId
                }
            );
            return { response };
        } catch (error) {
            console.log(error);
            return { error };
        }
    },

    addToGroup: async ({ chatId, userId }) => {
        try {
            const response = await privateClient.put(
                chatEndpoints.addToGroup, {
                    chatId,
                    userId
                }
            );
            return { response };
        } catch (error) {
            console.log(error);
            return { error };
        }
    },

}

export default chatApi;