import privateClient from '../client/private.client';
import publicClient from '../client/public.client';

const userEndpoints = {
	signin: '/user/signin',
	signup: '/user/signup',
	getUsers: ({ search }) => `/user?search=${search}`,
}

const userApi = {
    signup: async ({name, email, password, confirmPassword, pic}) => {
        //console.log(name, email, password, confirmPassword, pic)
        try {
            const response = await publicClient.post(
                userEndpoints.signup, {
                    name,
                    email,
                    password,
                    confirmPassword,
                    pic
                }
            );
            return { response };
        } catch (error) {
            console.log(error);
            return { error };
        }
    },

    signin: async ({ email, password }) => {
        try {
            const response = await publicClient.post(
                userEndpoints.signin, {
                    email,
                    password
                }
            );
            return { response };
        } catch (error) {
            console.log(error);
            return { error };
        }
    },

    getUsers: async ({ search }) => {
        try {
            const response = await privateClient.get(
                userEndpoints.getUsers({ search })
            );
            return { response };
        } catch (error) {
            console.log(error);
            return { error };
        }
    }
}


export default userApi;